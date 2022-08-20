// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// MPI_Send, MPI_Recv example. Communicates the number -1 from process 0
// to process 1.
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

  // We are assuming at least 2 processors for this task
  if (world_size < 2)
  {
    std::cerr << "World size must be greater than 1 for " << argv[0] << std::endl;
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  // The data we are going to send, -1 to see if default value has been changed
  // Processor 0 has the job to initialize it.
  int number = -1;

  // If this processor has rank 0, set the number to 42 and send it to processor 1
  if (world_rank == 0)
  {
    number = 42;

    MPI_Send(/* data         = */ &number,
             /* count        = */ 1,
             /* datatype     = */ MPI_INT,
             /* destination  = */ 1,
             /* tag          = */ 0,
             /* communicator = */ MPI_COMM_WORLD);

    std::cout
      << "Processor 0 sends number " << number
      << " to processor 1!" << std::endl;

  }
  else if (world_rank == 1)
  {
    MPI_Recv(/* data         = */ &number,
             /* count        = */ 1,
             /* datatype     = */ MPI_INT,
             /* source       = */ 0,
             /* tag          = */ 0,
             /* communicator = */ MPI_COMM_WORLD,
             /* status       = */ MPI_STATUS_IGNORE);

    std::cout
      << "Processor 1 received number " << number
      << " from processor 0!" << std::endl;
  }

  // Finalize the MPI environment. No more MPI calls can be made after this
  MPI_Finalize();

  return 0;
}