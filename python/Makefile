SHELL := /bin/bash
FILE := $(lastword $(MAKEFILE_LIST))

PROJECT := project

ifneq ($(wildcard) ./venv/.*),)
	VENV := "PRESENT"
else
	VENV := ""
endif

.PHONY: all \
	   	install \
	   	setup \
	   	env \
	   	run \
	   	update \
	   	format \
	   	docs \
	   	test \
	   	lint

env:
	python -m venv ./venv

install:
	# installs in developer mode
	pip3 install -e .

uninstall:
	# installs in developer mode
	pip uninstall ${PROJECT}

setup:
	python setup.py install

all:

run:
	notes -u daniel.duclos.cavalcanti@gmail.com -p $(shell pass show note)

debug:
	cd ${PROJECT} && ipdb3 __main__.py -u daniel.duclos.cavalcanti@gmail.com -p $(shell pass show note)

update:
	pip freeze > requirements.txt

format:
	# black ${PROJECT}

docs:
	# generate docs

test:
	pytest

lint:
	pylint ${PROJECT}

