// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// Comparison of MPI_Bcast with the my_bcast function
//

#include <iostream>

#include <mpi.h>

void my_bcast(void* data, int count,
              MPI_Datatype datatype, int root,
              MPI_Comm communicator)
{
  int world_rank, world_size;
  MPI_Comm_rank(communicator, &world_rank);
  MPI_Comm_size(communicator, &world_size);

  // If we are the root processor, send our data to everyone
  if (world_rank == root)
  {
    for (int i = 0; i < world_size; i++)
    {
      if (i != world_rank)
        MPI_Send(data, count, datatype, i, 0, communicator);
    }
  }

  // If we are a receiver processor, receive the data from the root
  else
  {
    MPI_Recv(data, count, datatype, root, 0, communicator, MPI_STATUS_IGNORE);
  }
}

int main(int argc, char* argv[])
{
  // Check the command line arguments
  if (argc != 3)
  {
    std::cerr << "Usage: compare_bcast num_elements num_trials" << std::endl;
    return 1;
  }

  // Parse the arguments
  int num_elements = atoi(argv[1]);
  int num_trials = atoi(argv[2]);

  // Initialize the MPI environment
  MPI_Init(&argc, &argv);

  // This time only the rank is required
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  // Stores the time, we use MPI's mechanism instead of std::chrono
  double total_my_bcast_time = 0.0;
  double total_mpi_bcast_time = 0.0;

  // The dummy data to send around, an array to make it more expensive
  int* data = new int[num_elements];

  // Repeat to get proper timing
  // Total delay accumulates with each iteration
  for (int i = 0; i < num_trials; i++)
  {
    // Time my_bcast

    // Synchronize before starting timing
    MPI_Barrier(MPI_COMM_WORLD);
    total_my_bcast_time -= MPI_Wtime();

    // Our Broadcast
    my_bcast(data, num_elements, MPI_INT, 0, MPI_COMM_WORLD);

    // Synchronize again before obtaining final time
    MPI_Barrier(MPI_COMM_WORLD);

    total_my_bcast_time += MPI_Wtime();

    // Time MPI_Bcast

    // Synchronize before starting timing
    MPI_Barrier(MPI_COMM_WORLD);
    total_mpi_bcast_time -= MPI_Wtime();

    // MPI's Broadcast
    MPI_Bcast(data, num_elements, MPI_INT, 0, MPI_COMM_WORLD);

    // Synchronize again before obtaining final time
    MPI_Barrier(MPI_COMM_WORLD);
    total_mpi_bcast_time += MPI_Wtime();
  }

  // Print off timing information on master
  if (world_rank == 0)
  {
    std::cout
      << "Data size = " << num_elements * (int)sizeof(int)
      << ", Trials = " << num_trials << std::endl;

    std::cout << "Avg my_bcast time = " << total_my_bcast_time / num_trials << std::endl;
    std::cout << "Avg MPI_Bcast time = " << total_mpi_bcast_time / num_trials << std::endl;
  }

  // Free the memory and set pointer to zero
  delete[] data;
  data = 0;

  // Finalize the MPI environment. No more MPI calls can be made after this
  MPI_Finalize();

  return 0;
}
