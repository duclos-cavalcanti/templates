SHELL := /bin/bash
FILE := $(lastword $(MAKEFILE_LIST))

DOCKER := thomasweise/texlive
NAME := latex-example

PWD := $(shell pwd)

exist-docker-image = $(shell docker image ls | grep ${DOCKER} | tr -s ' ' | cut -f2 -d ' ')
exist-docker-running = $(shell docker ps -a | grep ${DOCKER} | tr -s ' ' | cut -f2 -d ' ')

all:

.PHONY: help
help:
	$(info Toolchain version: Latex Template)
	$(info)
	$(info Targets: )
	$(info  * build         - Pulls docker: ${DOCKER})
	$(info  * run       	- Runs latex docker and instantiates this project onto running docker, then runs the make pdf target)
	$(info  * clean       	- Deletes outputted files)
	$(info  * reset     	- Cleans environemnt, deleting docker image and running version of it)
	$(info  * pdf     	    - Creates Project's pdf)
	$(info)


.PHONY: all
all: run

.PHONY: build
build:
	@echo "## Building Docker ##"
	@docker pull ${DOCKER}

.PHONY: clean
clean: run-clean
	@echo "## Removing Outputted files ##"
	@rm -fv project/*.pdf

.PHONY: reset
reset:
	@echo "## Resetting Docker Environment ##"
	@if [ -n "$(call exist-docker-running)" ]; then \
		docker rm ${NAME}; \
	fi
	@if [ -n "$(call exist-docker-image)" ]; then \
		docker rmi $(shell docker images --filter=reference="*${DOCKER}*" -q); \
	fi

.PHONY: run-clean
run-clean:
	@echo "## Cleaning Environment before run ##"
	@find -name '*.log' -exec rm -fv {} \;
	@find -name '*.aux' -exec rm -fv {} \;

.PHONY: run
run: $(if $(call exist-docker-image),,build) run-clean
	@echo "## Running Docker ##"
	@docker run --rm \
		   --name=${NAME} \
		   --user=$(shell id -u) \
		   --network=host \
		   -v ${PWD}:/doc \
		   -w /doc \
		   --detach-keys="ctrl-@" \
		   -it ${DOCKER} \
			bash -c 'make pdf'

.PHONY: pdf
pdf:
	@echo "## Creating pdf ##"
	@cd project && xelatex main.tex
