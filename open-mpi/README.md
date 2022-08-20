# OpenMPI-Tutorial

This project serves as a demonstration and learning example for the [`OpemMPI`](https://www.open-mpi.org/) Library. With the small bite-sized implementations 
of the OpenMPI interface coupled with the ease of use of `CMake`, make this repository an easy interactive way to look at this library and some of
its capabilities.

The Open MPI Project is an open source Message Passing Interface implementation that is developed and maintained by a consortium of academic, research, and industry partners. 
Open MPI is therefore able to combine the expertise, technologies, and resources from all across the High Performance Computing community in order to build the best MPI library available

The source files are not made by me and are taken from this [tutorial](www.mpitutorial.com), authored by Wes Kendall.

## Dependencies
1. `CMake`
2. `OpenMPI`

### Arch-based systems
```
sudo pacman -S cmake openmpi
```

## Usage
1. Build
```sh
cd build
cmake ..
make
```

1. Run
```sh
cd bin
mpirun -np <n> ./<target>
```
