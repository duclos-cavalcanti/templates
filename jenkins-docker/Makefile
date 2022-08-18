SHELL := /bin/bash
FILE := $(lastword $(MAKEFILE_LIST))

TAG := jenkins-template
REPO := jenkins
NAME := jenkins-example

exist-docker-image = $(shell docker image ls | grep ${TAG} | tr -s ' ' | cut -f2 -d ' ')
exist-docker-instance = $(shell docker ps -a | grep ${TAG} | tr -s ' ' | cut -f2 -d ' ')
exist-docker-running = $(shell docker ps -a -f name=${NAME} -f status=running)
ip-address = $(shell hostname -i | cut -d ' ' -f1)

all: 

.PHONY: help
help: 
	$(info Toolchain version: placeholder)
	$(info)
	$(info Targets: )
	$(info  * build         - Builds docker image with NAME:${NAME} and TAG:${TAG})
	$(info  * run       	- Run the built docker, should be called after build)
	$(info  * log       	- Prints the docker log, necessary to visualize password)
	$(info  * clean       	- Deletes Running Docker)
	$(info  * clean-img     - Deletes built Docker Image)
	$(info  * reset     	- Cleans environemnt, deleting docker image and instance version of it)
	@echo ""

.PHONY: build
build:
	@echo "## Building Docker ##"
	@docker build . -t ${TAG}:${REPO}
	@# docker pull jenkins/jenkins:latest will be done automatically

.PHONY: run
run: $(if $(call exist-docker-image),,build)
	@echo "## Running Docker ##"
	@if [ -n "$(call exist-docker-instance)" ]; then \
		echo "Docker already exists, either run make clean to run \
			  new docker instance or make restart to relaunch current one"; \
	else \
		docker run --name ${NAME} \
					-p 8080:8080 \
					-p 50000:50000 \
				    -v jenkins_home:/var/jenkins_home \
					-d \
				    --detach-keys="ctrl-@" \
				    -it ${TAG}:${REPO}; \
	fi
	@ # jenkins/jenkins:lts

.PHONY: log
log:
	@if [ -n "$(call exist-docker-instance)" ]; then \
		docker logs ${NAME}; \
	else \
		echo "First run 'make run' to run the jenkins docker"; \
	fi

.PHONY: stop
stop:
	@echo "## Stopping Docker ##"
	@if [ -n "$(call exist-docker-instance)" ]; then \
		docker stop ${NAME}; \
	fi

.PHONY: restart
restart:
	@echo "## Restarting Docker ##"
	@if [ -n "$(call exist-docker-instance)" ]; then \
		docker restart ${NAME}; \
	fi

.PHONY: clean
clean: $(if $(call exist-docker-running),,stop)
	@echo "## Removing Docker ##"
	@if [ -n "$(call exist-docker-instance)" ]; then \
		docker rm ${NAME}; \
	fi

.PHONY: clean-img
clean-img:
	@echo "## Removing Docker Image ##"
	@if [ -n "$(call exist-docker-image)" ]; then \
		docker rmi $(shell docker images --filter=reference="*jenkins*" -q); \
	fi

.PHONY: reset
reset: clean clean-img
	@echo "## Finished Resetting Docker Environment ##"
