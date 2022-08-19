SHELL := /bin/bash
FILE := $(lastword $(MAKEFILE_LIST))

STYLE := google

all: format

.PHONY: gnu google llvm chromium mozilla webkit microsoft

format:
	@echo "## Format Style: ${STYLE} ##"
	@for f in $$(ls src/*.c); do \
		clang-format -style=${STYLE} -i $$f ; \
		echo Formatting $$f ; \
	done
	@for f in $$(ls lib/*.c); do \
		clang-format -style=${STYLE} -i $$f ; \
		echo Formatting $$f ; \
	done
	@for f in $$(ls lib/include/*.h); do \
		clang-format -style=${STYLE} -i $$f ; \
		echo Formatting $$f ; \
	done
	@for f in $$(ls include/*.h); do \
		clang-format -style=${STYLE} -i $$f ; \
		echo Formatting $$f ; \
	done

check:
	# cpp check
	echo "NOT IMPLEMENTED YET"

