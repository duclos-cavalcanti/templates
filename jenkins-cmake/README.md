# Jenkins-CMake-Template
## Table of Contents
1. [Introduction](#introduction)
2. [Tools](#tools)
3. [Targets](#targets)

<a name="introduction"/>

## 1. Introduction
Repo aims to display a template/bare use of `Jenkins Pipelines` for a dummy project with the use of a Jenkins
Docker and the automation of this all with a Makefile.

<a name="tools"/>

## 2. Tools
1. `Makefile`: 
    * Abstracts/automates the steps to get the project running and interact with it.
2. `Jenkinsfile`
    * Describes the Jenkins `pipeline` with different stages, uses dummy groovy scripts,
      defines environment variables and aims to show the basic capabilities of a
      multibranch pipeline with a declarative jenkinsfile.

<a name="targets"/>

## 3. Targets
1. `make build`: 
    * Builds the jenkins docker specified by the **Dockerfile**.
2. `make run`: 
    * Run the built jenkins docker.

4. `make clean`
    * Deletes running jenkins docker.

<a name="quickstart"/>

