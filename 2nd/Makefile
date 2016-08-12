
CXX = g++
CXX_FLAGS = -std=c++11 -g

EDITOR := vim
SLUG := $(shell echo '${NAME}' | sed -e 's/[^[:alnum:]]/_/g' | tr -s '_' | tr A-Z a-z)
EXT ?= cpp

LAST_CPP := $(shell ls -lt *.cpp | head -1 | awk '{print $$NF}')

build: ${LAST_CPP}
	${CXX} ${CXX_FLAGS} ${LAST_CPP}

edit:
	${EDITOR} ${LAST_CPP}

help:
	@echo 'Makefile for leetcode practice'
	@echo 'Usage:'
	@echo '    make build:      bulid a solution'
	@echo '    make edit:       edit the lastest solution'
	@echo '    make help:       show this help'
	@echo '    make solution:   new a solution'
	@echo '    make test:       test the lastest solution'

solution:
ifdef NAME
	${EDITOR} ./${SLUG}.${EXT}
else
	@echo 'Variable NAME is not defined.'
	@echo 'Do make solution NAME='"'"'Solution Name'"'"
endif

test:
	./a.out

.PHONY: solution help build test
