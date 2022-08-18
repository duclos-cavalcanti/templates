SHELL := /bin/bash

PROJECT := project
MODULE := github.com/duclos-cavalcanti/go-project-template

GO ?= go
FMT ?= gofmt
DEBUG ?= dlv debug
DIR := cmd

SRC ?= $(shell find $(DIR) -name "*.go" -type f)
FLAGS ?=
LDFLAGS ?=


all: build

.PHONY: init
init:
	$(GO) mod init $(MODULE)

.PHONY: build
build:
	$(GO) build -v -o $(PROJECT) $(FLAGS) cmd/*.go

.PHONY: run
run:
	./$(PROJECT)

.PHONY: debug
debug:
	$(DEBUG) ${DIR}/main.go

.PHONY: fmt
fmt:
	$(FMT) -w $(SRC)

# UNTESTED!
.PHONY: test
test:
	go test -v ./...

.PHONY: cover
cover:
	go test ./... -cover

.PHONY: docs
docs:
	godoc -http=:6060
	@ # godoc -url http://localhost:6060/pkg/github.com/duclos-cavalcanti/go-project-template > docs/index.html

.PHONY: tidy
tidy:
	$(GO) mod tidy

.PHONY: clean
clean:
	$(GO) clean -modcache
