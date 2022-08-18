# Jenkins-Pipeline-Template
## Table of Contents
1. [Introduction](#introduction)
2. [Tools](#tools)
3. [Targets](#targets)
4. [Quickstart](#quickstart)
5. [Jenkins](#jenkins)

<a name="introduction"/>

## 1. Introduction
Repo aims to display a template/bare use of `Jenkins Pipelines` for a dummy project with the use of a Jenkins
Docker and the automation of this all with a Makefile.

<a name="tools"/>

## 2. Tools
1. `Dockerfile`: 
    * Needed to pull/build/run the jenkins docker
2. `Makefile`: 
    * Abstracts/automates the steps to get the project running and interact with it.
3. `Jenkinsfile`
    * Describes the Jenkins `pipeline` with different stages, uses dummy groovy scripts,
      defines environment variables and aims to show the basic capabilities of a
      multibranch pipeline with a declarative jenkinsfile.

<a name="targets"/>

## 3. Targets
1. `make build`: 
    * Builds the jenkins docker specified by the **Dockerfile**.
2. `make run`: 
    * Run the built jenkins docker.
3. `make log`
    * Runs *docker log* which shows the current output of the running jenkins docker.
      Needed to visualize the created password to login into the jenkins instance on
      [localhost:8080](http://localhost:8080/).

4. `make clean`
    * Deletes running jenkins docker.
5. `make clean-img`
    * Deletes created jenkins docker image.
6. `make reset`
    * Calls upon `make clean` and `make clean-img`, resetting the entire project.

<a name="quickstart"/>

## 4. Quickstart
**TODO**

<a name="jenkins"/>

## 5. Jenkins
Small quick intro to Jenkins and it's main *bullet points*. `Jenkins` is one of and a very
powerful Software that aims to automate the continuous integration and continuous
development of projects. In a way it serves as an automated manner to build, test and
deploy products in a very flexible and intuitive fashion.

### Jobs
These are the bread and butter of Jenkins. They are like the project's that Jenkins
periodically manages and waits on events to trigger its building, testing, deployment or *whathaveyou*.

* `Freestyle`
    * Useful for simple, single tasks like running tests.

* `Pipeline`
    * Whole delivery cycle, like test + build + deploy.

* `Multibranch Pipeline`
    * Like pipeline but for multiple branches of one repo.

### Pipeline Syntax
Ways in which these pipelins can be written / defined / scripted.
* `Scripted`
    * First syntax, uses groovy engine, nodes are scripted through groovy script. It has
    advanced capabilities, vaery flexible.

* `Declarative`
    * Predefined structure, easier to get started, more rigig.

### Credentials
These are **sign-in** keys needed to pull or access git repo's. Their main attributes are:
1. `IDs`: Important, their names are referenced by Jenkinsfiles.
2. `Scopes`:
    * System
        * Only available on Jenkins server, not for Jenkins jobs.

    * Global
        * Everywhere accessible

    * Project
        * Only usable in multibranch pipelins, limited to the project in question.


### Branch Discovery
Definition of which branches in a git project will Jenkins watch for to perform it's jobs
or stages.

Example Regex definition:
```regex
.*dev|.*feature
```
Branch ends in either *dev* or *feature*.

### Tools
As you develop your application, you want jenkins to build and package said application.
For that purpose it needs tools to do so. Example pre-installed tools are:
- Ant
- Gradle
- Maven

One can install nodejs, npm, yarn, Docker, etc.

1. Go to Jenkins -> Manage Jenkins -> Global Tool Configuration
2. Configure the wanted plugin
3. Change Jenkinsfiles to encorporate the plugins and their commands in their jobs.

### Trigger Jenkins Automatically / Periodically
Two ways to trigger jenkins jobs:

1. `Push Notifications`
    * Version control notifies Jenkins on new commit. (May Require to install jenkins plugin for Github / Gitea / Gitlab)
    * In the case of Github: 
        1. At the Github Repo in question, go to Settings->Webhooks and add a Webhook.
        You will need a public domain to allow github to send a hook to your local server. 
        Here are the [docs ](https://expose.sh/docs).
        ```
        curl -s https://expose.sh/sh/install-linux.sh | sudo bash
        ```
        2. Go to System Configuration -> Manage Jenkins on the Jenkins Server

2. `Polling`
    * Jenkins polls in regular intervalls.
