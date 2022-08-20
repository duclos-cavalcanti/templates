// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// An example of a function that implements MPI_Bcast using MPI_Send and
// MPI_Recv
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

int main(int argc, char** argv)
{
  // Initialize the MPI environment
  MPI_Init(&argc, &argv);

  // This time only the rank is required
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  // The dummy data to send around
  int data;

  // Processor zero sends
  if (world_rank == 0)
  {
    data = 42;
    std::cout << "Processor is 0 broadcasting data: " << data << std::endl;
    my_bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
  }

  // The rest listens
  else
  {
    my_bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    std::cout
      << "Processor " << world_rank
      << " received data " << data
      << " from root processor!" << std::endl;
  }

  // Finalize the MPI environment. No more MPI calls can be made after this
  MPI_Finalize();

  return 0;
}