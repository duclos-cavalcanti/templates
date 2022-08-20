// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// Example of using MPI_Probe to dynamically allocated received messages
//

#include <iostream>
#include <random>

#include <mpi.h>

int main(int argc, char* argv[])
{
  // Initialize the MPI environment
  MPI_Init(&argc, &argv);

  int world_size, world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // We are assuming exactly 2 processors for this task
  if (world_size != 2)
  {
    std::cerr << "World size must be two for " << argv[0] << std::endl;
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  // Variables for the data to send
  int number_amount;

  // Processor zero picks a random amount of integers (at least one) and sends them to processor one
  if (world_rank == 0)
  {
    // Now the size is only available at processor zero
    const int MAX_NUMBERS = 15;
    int numbers[MAX_NUMBERS];

    // For a single time use this can go here, otherwise it should be persistent as in HA1
    std::random_device random_device;                             // Generates good seeds
    std::mt19937 random_engine(random_device());                  // Initialie the Mersenne Twister with that Seed
    std::uniform_int_distribution<> rand_int(1, MAX_NUMBERS - 1); // Left and right border are included

    // Random amount of numbers to send
    number_amount = rand_int(random_engine);

    // Generate Data
    for (int i = 0; i < number_amount; i++)
      numbers[i] = rand_int(random_engine);

    // Send the amount of integers to processor one
    MPI_Send(numbers, number_amount, MPI_INT, 1, 0, MPI_COMM_WORLD);

    std::cout
      << "Processor " << world_rank
      << " sent " << number_amount
      << " numbers to " << 1 << std::endl;
  }
  // Processor one waits for a message without knowing what is coming
  else if (world_rank == 1)
  {
    // Stores additional information about the message
    MPI_Status status;

    // Probe (prior to receive) for an incoming message from processor zero
    MPI_Probe(0, 0, MPI_COMM_WORLD, &status);

    // When probe returns, the status object has the size and other
    // attributes of the incoming message. Get the size of the message.
    MPI_Get_count(&status, MPI_INT, &number_amount);

    // Allocate a buffer just big enough to hold the incoming numbers
    // std::vector<int> with correct size also works. For the MPI function use the pointer to the first element.
    int* number_buffer = new int[number_amount];

    // Now receive the message with the allocated buffer
    // We already have the status object -> ignore it now
    MPI_Recv(number_buffer, number_amount, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    // Print off the amount of numbers, and also print additional information
    // in the status object
    std::cout
      << "Processor " << world_rank
      << " received dynamically " << number_amount
      << " numbers from " << 0 << std::endl;

    std::cout
      << "Message: " << "\n"
      << " source = " << status.MPI_SOURCE << "\n"
      << " tag = " << status.MPI_TAG << std::endl;

    // Print the numbers to the console
    std::cout << "The numbers: ";
    for (int i = 0; i < number_amount; i++)
      std::cout << number_buffer[i] << " ";
    std::cout << std::endl;

    // Free the memory and set pointer to zero
    delete[] number_buffer;
    number_buffer = 0;
  }

  // Wait for others
  MPI_Barrier(MPI_COMM_WORLD);

  // Finalize the MPI environment. No more MPI calls can be made after this
  MPI_Finalize();

  return 0;
}