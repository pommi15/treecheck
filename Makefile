# Makefile for treecheck
# Thomas Rauhofer and Tobias Watzek

CC=g++
CFLAGS=-g -Wall -std=c++11

all: treecheck

treecheck: treeccheck.o txtImport.o
	${CC} ${CFLAGS} txtImport.o -o treecheck

treecheck.o: treecheck.cpp
	${CC} ${CFLAGS} -c treeccheck.cpp -o treeccheck.o

txtImport.o: txtImport.cpp
	${CC} ${CFLAGS} -c txtImport.cpp -o txtImport.o
