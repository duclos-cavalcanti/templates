SHELL := /bin/bash
FILE := $(lastword $(MAKEFILE_LIST))

PWD := $(shell pwd)
SRC_DIR := ${PWD}/src
TEST_DIR := ${PWD}/test
BUILD_DIR := ${PWD}/build

CC := ghdl
CC_FLAGS := --workdir=${BUILD_DIR}

# top level entity to simulate
SIM := pwm_tb

SRC_FILES := $(shell find ${SRC_DIR} -name '*.vhd')
TEST_FILES := $(shell find ${TEST_DIR} -name '*.vhd')
VHDL_FILES := ${SRC_FILES} ${TEST_FILES}

WAVE := gtkwave
WAVE_FILE := ${PWD}/out.gwh

RUN_FLAGS := --stop-time=1000ns --vcd=${WAVE_FILE} --stats

all: compile run view

.PHONY: help
help: 
	$(info Toolchain version: GHDL Template)
	$(info)
	$(info Targets: )
	$(info  * compile       - compiles all vhdl files)
	$(info  * run       	- runs compiled simulation of the top entity/file)
	$(info  * view     	    - views waveform simulation)
	$(info  * clean       	- deletes outputted files)
	$(info)


.PHONY: compile
compile: clean
	@echo "** Compiling VHDL files **"
	@$(CC) -a -g $(CC_FLAGS) $(VHDL_FILES)
	@$(CC) -e $(CC_FLAGS) ${SIM}
	@mv *${SIM}* ${BUILD_DIR}

.PHONY: debug
debug:
	@echo "** Debugging Simulation **"
	@gdb ${SIM}

.PHONY: run
run: compile
	@echo "** Running VHDL Simulation **"
	@cd ${BUILD_DIR} && $(CC) -r $(CC_FLAGS) ${SIM} $(RUN_FLAGS)

.PHONY: view
view:
	@echo "** Viewing VHDL Simulation Waveform **"
	@$(WAVE) $(WAVE_FILE)

.PHONY: clean
clean:
	@echo "** Removing Outputted files **"
	@find -name '*.cf' -exec rm -fv {} \;
	@find -name '*.gwh' -exec rm -fv {} \;
	@rm -fv ${BUILD_DIR}/*
	@touch ${BUILD_DIR}/.gitkeep

