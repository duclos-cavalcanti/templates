// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// Example application of random walking using MPI_Send, MPI_Recv, and
// MPI_Probe.
//

#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>

#include <mpi.h>

// Single global random number generator
std::random_device random_device;                   // Generates good seeds
std::mt19937 random_engine(random_device());        // Initialie the Mersenne Twister with that Seed
std::uniform_real_distribution<> uniform(0.0, 1.0); // Range is [0,1[

// Represent a walker
struct WalkerType
{
  WalkerType(int a = 0, int b = 10) : location(a), num_steps_left_in_walk(b) {}

  int location;
  int num_steps_left_in_walk;
};

void decompose_domain(int domain_size,
                      int world_rank, int world_size,
                      int& subdomain_start, int& subdomain_size)
{

  // Don't worry about this special case. Assume the domain size
  // is greater than the world size.
  if (world_size > domain_size)
    MPI_Abort(MPI_COMM_WORLD, 1);

  // Write to references
  subdomain_start = domain_size / world_size * world_rank;
  subdomain_size = domain_size / world_size;

  // Give remainder to last process
  if (world_rank == world_size - 1)
    subdomain_size += domain_size % world_size;
}

void initialize_walkers(int num_walkers_per_proc, int max_walk_size,
                        int subdomain_start,
                        std::vector<WalkerType>& incoming_walkers)
{
  WalkerType walker;

  // Initialize walkers at the start of the subdomain
  for (int i = 0; i < num_walkers_per_proc; i++)
  {
    walker.location = subdomain_start;
    walker.num_steps_left_in_walk = int(uniform(random_engine) * max_walk_size);

    incoming_walkers.push_back(walker);
  }
}

void walk(WalkerType& walker,
          int subdomain_start, int subdomain_size, int domain_size,
          std::vector<WalkerType>& outgoing_walkers)
{
  while (walker.num_steps_left_in_walk > 0)
  {
    // The walker is at the end of this subdomain
    if (walker.location == subdomain_start + subdomain_size)
    {
      // The walker is also at the end of the whole domain
      // -> wrapping it around to the beginning
      if (walker.location == domain_size)
        walker.location = 0;

      outgoing_walkers.push_back(walker);

      break;
    }
    // Location increased, one step less to walk
    else
    {
      walker.num_steps_left_in_walk--;
      walker.location++;
    }
  }
}

void send_outgoing_walkers(std::vector<WalkerType>& outgoing_walkers,
                           int world_rank, int world_size)
{
  // Send the data as an array of MPI_BYTEs to the next processor.
  // The last processor sends to processor zero.
  MPI_Send((void*)outgoing_walkers.data(),
           outgoing_walkers.size() * sizeof(WalkerType), MPI_BYTE,
           (world_rank + 1) % world_size, 0, MPI_COMM_WORLD);

  // Clear the outgoing walkers list
  outgoing_walkers.clear();
}

void receive_incoming_walkers(std::vector<WalkerType>& incoming_walkers,
                              int world_rank, int world_size)
{
  // Probe for new incoming walkers
  MPI_Status status;

  // Receive from the processor before you. If you are processor zero,
  // receive from the last processor
  int incoming_rank = (world_rank == 0) ? world_size - 1 : world_rank - 1;

  // Now do the probing
  MPI_Probe(incoming_rank, 0, MPI_COMM_WORLD, &status);

  // Required size of incoming walker buffer based on how much data is being received
  int incoming_walkers_size;
  MPI_Get_count(&status, MPI_BYTE, &incoming_walkers_size);

  // Resize -> number of bytes devided by bytes per walker
  incoming_walkers.resize(incoming_walkers_size / sizeof(WalkerType));

  // Now get the data by providing a void pointer (where MPI can write to)
  MPI_Recv((void*)incoming_walkers.data(),
           incoming_walkers_size, MPI_BYTE,
           incoming_rank, 0, MPI_COMM_WORLD,
           MPI_STATUS_IGNORE);
}

int main(int argc, char* argv[])
{
  int domain_size, max_walk_size, num_walkers_per_proc;

  // Check the command line arguments
  if (argc < 4)
  {
    std::cerr << "Usage: random_walk domain_size max_walk_size num_walkers_per_proc" << std::endl;
    return 1;
  }

  // Parse the arguments
  domain_size = atoi(argv[1]);
  max_walk_size = atoi(argv[2]);
  num_walkers_per_proc = atoi(argv[3]);

  // Initialize the MPI environment
  MPI_Init(&argc, &argv);

  // Find out rank and size
  int world_size, world_rank;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  int subdomain_start, subdomain_size;
  std::vector<WalkerType> incoming_walkers, outgoing_walkers;

  // Find your part of the domain
  decompose_domain(domain_size, world_rank, world_size, subdomain_start, subdomain_size);

  // Initialize walkers in your subdomain
  initialize_walkers(num_walkers_per_proc, max_walk_size, subdomain_start, incoming_walkers);

  // For the user
  std::cout
    << "Processor " << world_rank << " initiated " << num_walkers_per_proc
    << " walkers in subdomain " << subdomain_start << " - "
    << subdomain_start + subdomain_size - 1 << std::endl;

  // Determine the maximum amount of sends and receives needed to complete all walkers
  int maximum_sends_recvs = max_walk_size / (domain_size / world_size) + 1;

  // Here comes the work
  for (int m = 0; m < maximum_sends_recvs; m++)
  {
    // Handle all incoming walkers
    for (unsigned int i = 0; i < incoming_walkers.size(); i++)
      walk(incoming_walkers[i], subdomain_start, subdomain_size, domain_size, outgoing_walkers);

    // For the user
    std::cout
      << "Processor " << world_rank << " sending " << outgoing_walkers.size()
      << " outgoing walkers to processor " << (world_rank + 1) % world_size << std::endl;

    // Half of the processors change the order of statements -> no deadlock
    if (world_rank % 2 == 0)
    {
      // Send all outgoing walkers to the next procesor.
      send_outgoing_walkers(outgoing_walkers, world_rank, world_size);

      // Receive all the new incoming walkers
      receive_incoming_walkers(incoming_walkers, world_rank, world_size);
    }
    else
    {
      // Receive all the new incoming walkers
      receive_incoming_walkers(incoming_walkers, world_rank, world_size);

      // Send all outgoing walkers to the next processor
      send_outgoing_walkers(outgoing_walkers, world_rank, world_size);
    }

    // For the user
    std::cout
      << "Processor " << world_rank
      << " received " << incoming_walkers.size()
      << " incoming walkers" << std::endl;
  }

  // For the user
  std::cout << "Processor " << world_rank << " done" << std::endl;

  // Finalize the MPI environment. No more MPI calls can be made after this
  MPI_Finalize();

  return 0;
}