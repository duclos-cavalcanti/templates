SHELL := /bin/bash

STACK ?= stack
CABAL ?= cabal
FMT ?= cabal-fmt
DIR ?= src

SRC ?= $(shell find $(DIR) -name "*.hs" -type f)
FLAGS ?=

all:

.PHONY: clean
clean:
	$(STACK) clean

.PHONY: purge
purge:
	@$(STACK) purge

.PHONY: build
build: clean
	@$(STACK) build

.PHONY: test
test:
	@$(STACK) test

.PHONY: run
run:
	@$(STACK) exec template-bin

.PHONY: fmt
fmt:
	$(FMT) $(SRC)

.PHONY: docs
docs:
	$(CABAL) haddock
