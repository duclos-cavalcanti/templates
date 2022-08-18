SHELL := /bin/bash
FILE := $(lastword $(MAKEFILE_LIST))

all: 

.PHONY: help
help: 
	$(info Toolchain version: placeholder)
	$(info)
	$(info Targets: )
	@echo ""

.PHONY: build
build:
	@echo "## Building project ##"
	@cd project/build && cmake ..
	@cd project/build && make

.PHONY: run
run:
	@echo "## Running project ##"
	@cd project/bin && ./bar

.PHONY: dummy1
dummy1:
	@echo "## Dummy 1 ##"
	@cd project/build && make test1

.PHONY: dummy2
dummy2:
	@echo "## Dummy 2 ##"
	@cd project/build && make test2

.PHONY: clean
clean:
	@cd project/build && make reset
