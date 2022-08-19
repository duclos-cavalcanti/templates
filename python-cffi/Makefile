SHELL := /bin/bash
FILE := $(lastword $(MAKEFILE_LIST))
CWD := $(shell pwd)
FOLDER := $(shell basename ${CWD})

.PHONY: all
all:

.PHONY: help
help: 
	$(info Toolchain version: placeholder)
	$(info)
	$(info Targets: )
	$(info  * run           - Runs Python frontend)
	$(info  * build         - Builds project)
	$(info  * test          - Runs unit-tests)
	$(info  * clean       	- Cleans project)
	@echo ""

.PHONY: clean
clean:
	@echo -e '\n** CLEANING PROJECT'
	@rm -rf __pycache__
	@${MAKE} -C backend/ clean
	@rm -f *.so
	@rm -f *.o
	@rm -f *.cpp

.PHONY: build
build: clean
	@echo -e "\n** BUILDING PROJECT"
	@${MAKE} -C backend/ build
	@python3 compile.py

.PHONY: test
test:
	@echo -e '\n** TESTING PROJECT'
	@python3 -m pytest -v tests/

.PHONY: run
run:
	@echo -e '\n** RUNNING PROJECT'
	@python3 main.py
