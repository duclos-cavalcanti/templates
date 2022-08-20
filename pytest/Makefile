SHELL := /bin/bash
FILE := $(lastword $(MAKEFILE_LIST))
PWD := $(shell pwd)
FOLDER := $(shell basename ${PWD})

.PHONY: all
all: run

.PHONY: clean
clean:
	@rm -rf __pycache__

.PHONY: test
test:
	@python3 -m pytest -v tests/

.PHONY: run
run:
	@python3 src/main.py
