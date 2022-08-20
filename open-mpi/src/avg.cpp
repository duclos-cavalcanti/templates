// Author: Wes Kendall
// Copyright 2012 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// Program that computes the average of an array of elements in parallel using
// MPI_Scatter and MPI_Gather
//
#include <iostream>
#include <cstdlib>
#include <random>

#include <mpi.h>

// Single global random number generator
std::random_device random_device; // Generates good seeds
std::mt19937 random_engine(random_device()); // Initialie the Mersenne Twister with that Seed
std::uniform_real_distribution<> uniform(0.0, 1.0);

// Creates an array of random numbers. Each number has a value from 0 - 1
float* create_rand_nums(int num_elements)
{
  float* rand_nums = new float[num_elements];

  for (int i = 0; i < num_elements; i++)
    rand_nums[i] = uniform(random_engine);

  return rand_nums;
}

// Computes the average of an array of numbers
float compute_avg(float* array, int num_elements)
{
  float sum = 0.f;

  for (int i = 0; i < num_elements; i++)
    sum += array[i];

  return sum / num_elements;
}

int main(int argc, char* argv[])
{
  // Check the command line arguments
  if (argc != 2)
  {
    std::cerr << "Usage: avg num_elements_per_proc" << std::endl;
    return 1;
  }

  // Parse the arguments
  int num_elements_per_proc = atoi(argv[1]);

  // Initialize the MPI environment
  MPI_Init(&argc, &argv);

  // Find out rank and size
  int world_rank, world_size;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Create a random array of elements on the root process. Its total
  // size will be the number of elements per process times the number
  // of processes
  float* rand_nums = 0;

  if (world_rank == 0)
    rand_nums = create_rand_nums(num_elements_per_proc * world_size);

  // For each process, create a buffer that will hold a subset of the entire array
  float* sub_rand_nums = new float[num_elements_per_proc];

  // Scatter the random numbers from the root process to all processes in the MPI world
  MPI_Scatter(/*void*        send_data =     */ rand_nums,
              /*int          send_count =    */ num_elements_per_proc,
              /*MPI_Datatype send_datatype = */ MPI_FLOAT,
              /*void*        recv_data =     */ sub_rand_nums,
              /*int          recv_count =    */ num_elements_per_proc,
              /*MPI_Datatype recv_datatype = */ MPI_FLOAT,
              /*int          root =          */ 0,
              /*MPI_Comm     communicator =  */ MPI_COMM_WORLD);

  // Compute the average of your subset
  float sub_avg = compute_avg(sub_rand_nums, num_elements_per_proc);

  // Gather all partial averages down to the root process
  float* sub_avgs = 0;

  if (world_rank == 0)
    sub_avgs = new float[world_size];

  MPI_Gather(/*void*        send_data =     */ &sub_avg,
             /*int          send_count =    */ 1,
             /*MPI_Datatype send_datatype = */ MPI_FLOAT,
             /*void*        recv_data =     */ sub_avgs,
             /*int          recv_count =    */ 1,
             /*MPI_Datatype recv_datatype = */ MPI_FLOAT,
             /*int          root =          */ 0,
             /*MPI_Comm     communicator =  */ MPI_COMM_WORLD);

  // Now that we have all of the partial averages on the root, compute the
  // total average of all numbers. Since we are assuming each process computed
  // an average across an equal amount of elements, this computation will
  // produce the correct answer.
  if (world_rank == 0)
  {
    float avg = compute_avg(sub_avgs, world_size);

    // Compute the average across the original data for comparison
    float original_data_avg = compute_avg(rand_nums, num_elements_per_proc * world_size);

    std::cout << "Avg of all elements is " << avg << std::endl;
    std::cout << "Avg computed across original data is " << original_data_avg << std::endl;
  }

  // Clean up
  if (world_rank == 0)
  {
    delete[] rand_nums;
    delete[] sub_avgs;
  }
  delete[] sub_rand_nums;

  // Wait for all to ensure proper deleting  
  MPI_Barrier(MPI_COMM_WORLD);

  // Finalize the MPI environment. No more MPI calls can be made after this
  MPI_Finalize();

  return 0;
}