# Latex-Docker-Template

## Introduction
A simple project template to be able to create `pdf` documents with latex in a
containerized manner. 

Latex packages and/or a latex environment can be somewhat daunting,
messy and heavy. However being able to build a clean isolated environment with all the needed
packages can be useful and easily reproducible.

This repo was based upon these projects: 
- [docker-texlive](https://github.com/thomasWeise/docker-texlive)
- [Awesome-CV](https://github.com/posquit0/Awesome-CV)


## Getting Started
The only step needed is `make run`. This is so because, if the needed docker image is not
found locally, it will be automatically pulled. Afterwards the docker will be run and this
project will be instantiated as a volume directly onto it. 

The command run on the docker will be the `make pdf` target, which will take care of generating the
needed pdf. Since this volume is shared between docker and host, we will be able to
directly see our outputted pdf file.

## Targets
1. `make build`:
    - pulls the `thomasweise/texlive` docker image
    - is a dependency of `make run`
2. `make run`
    - runs the `thomasweise/texlive` docker, instantiating this project as a volume and then running `make pdf` on said docker.
3. `make clean`
    - cleans outputted and unnecessary files.
4. `make pdf`
    - generates our pdf file.
5. `make reset`
    - deletes a running docker if there is one and the pulled docker image.
