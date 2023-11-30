SHELL := /bin/bash
PWD := $(shell pwd)

all:
.PHONY: clean run debug test

clean:
	@rm -rf __pycache__

run:
	@python3 main.py

debug:
	@ipdb3 main.py

test:
	@python3 -m pytest -v tests/


