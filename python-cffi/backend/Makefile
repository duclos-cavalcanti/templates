SHELL := /bin/bash
FILE := $(lastword $(MAKEFILE_LIST))

.PHONY: all
all:

.PHONY: help
help: 
	$(info Toolchain version: placeholder)
	$(info)
	$(info Targets: )
	$(info  * build         - Builds backend)
	$(info  * clean       	- Cleans backend project)
	@echo ""

.PHONY: clean
clean:
	@echo -e '\n** CLEANING BACKEND'
	@rm -rf build/*
	@touch build/.gitkeep

.PHONY: build
build: clean
	@echo -e '\n** BUILDING BACKEND'
	cd build/ && cmake -DCMAKE_BUILD_TYPE=Release ..
	@$(MAKE) -C build/
	@echo -e '\n** INSTALLING BACKEND'
	@$(MAKE) -C build/ install
