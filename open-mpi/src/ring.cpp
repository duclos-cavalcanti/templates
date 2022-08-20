// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// Example using MPI_Send and MPI_Recv to pass a message around in a ring.
//

#include <iostream>

#include <mpi.h>

int main(int argc, char* argv[])
{
  // Initialize the MPI environment
  MPI_Init(&argc, &argv);

  // Find out rank and size
  int world_rank, world_size;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // A tracer to see the interaction, -1 to see if default value has been changed
  // Processor 0 has the job to initialize it
  int token = -1;

  // Holds the rank of the partner where this processor sends the token
  int partner_rank;

  // Receive from the lower processor and send to the higher processor.
  // Take care of the special case when this is the first processor (rank = 0)
  // to prevent deadlock.
  if (world_rank != 0)
  {
    partner_rank = world_rank - 1;

    MPI_Recv(&token, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    std::cout
      << "Processor " << world_rank
      << " received token " << token
      << " from processor " << partner_rank << std::endl;
  }
  // Set the token's value if this is process 0
  else
  {
    token = 42;
  }

  MPI_Send(&token, 1, MPI_INT, (world_rank + 1) % world_size, 0, MPI_COMM_WORLD);

  // Now processor 0 can receive from the last processor.
  // This makes sure that at least one MPI_Send is initialized before
  // all MPI_Recvs (again, to prevent deadlock)
  if (world_rank == 0)
  {
    partner_rank = world_size - 1;

    MPI_Recv(&token, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    std::cout
      << "Processor " << world_rank
      << " received token " << token
      << " from processor " << partner_rank << std::endl;
  }

  // Finalize the MPI environment. No more MPI calls can be made after this
  MPI_Finalize();

  return 0;
}