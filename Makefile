# Makefile for treecheck
# Thomas Rauhofer and Tobias Watzek

CC=g++
CFLAGS=-g -Wall -std=c++11

all: treecheck

treecheck: treecheck.o txtImport.o tree.o
	${CC} ${CFLAGS} txtImport.o tree.o -o treecheck

treecheck.o: treecheck.cpp
	${CC} ${CFLAGS} -c treecheck.cpp -o treecheck.o

txtImport.o: txtImport.cpp
	${CC} ${CFLAGS} -c txtImport.cpp -o txtImport.o

tree.o: tree.cpp
	${CC} ${CFLAGS} -c tree.cpp -o tree.o
