# Alex Paquette
# Makefile for lab three
# 2-Oct-2023

CC=g++
CPPFILES = Semaphore.cpp Barrier.cpp main.cpp
HFILES = Barrier.h Semaphore.h
OBJFILES = Barrier.o main.o Semaphore.o
CFLAGS = -std=c++11 -pthread -I. -Wall
EXE = barrier

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(OBJFILES) $(HFILES)
	$(CC) -o $(EXE) $(OBJFILES) $(CFLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

CLEAN:
	rm $(OBJFILES) $(EXE)

INSTALL:
	cp ./barrier /usr/bin/barrier