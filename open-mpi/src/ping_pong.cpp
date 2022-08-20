// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// Ping pong example with MPI_Send and MPI_Recv. Two processes ping pong a
// number back and forth, incrementing it until it reaches a given value.
//

#include <iostream>

#include <mpi.h>

int main(int argc, char* argv[])
{
  const int PING_PONG_LIMIT = 5;

  // Initialize the MPI environment
  MPI_Init(&argc, &argv);

  // Find out rank and size
  int world_rank, world_size;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // We are assuming exactly 2 processors for this task
  if (world_size != 2)
  {
    std::cerr << "World size must be two for " << argv[0] << std::endl;
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  int ping_pong_count = 0;
  int partner_rank = (world_rank + 1) % 2;

  while (ping_pong_count < PING_PONG_LIMIT)
  {
    if (world_rank == ping_pong_count % 2)
    {
      // Increment the ping pong count before you send it
      ping_pong_count++;

      MPI_Send(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD);

      std::cout
        << "Processor " << world_rank
        << " sent     ++ping_pong_count " << ping_pong_count
        << " to   " << partner_rank << std::endl;
    }
    else
    {
      MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);

      std::cout
        << "Processor " << world_rank
        << " received   ping_pong_count " << ping_pong_count
        << " from " << partner_rank << std::endl;
    }
  }

  // Finalize the MPI environment. No more MPI calls can be made after this
  MPI_Finalize();

  return 0;
}