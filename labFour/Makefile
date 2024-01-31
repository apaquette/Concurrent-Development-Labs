# Alex Paquette
# Makefile for lab four
# 9-Oct-2023

CC=g++
CPPFILES = Semaphore.cpp SafeBuffer.cpp Event.cpp main.cpp
HFILES = SafeBuffer.h Semaphore.h Event.h
OBJFILES = SafeBuffer.o main.o Semaphore.o Event.o
CFLAGS = -std=c++11 -pthread -I. -Wall
EXE = safeBuffer

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(OBJFILES) $(HFILES)
	$(CC) -o $(EXE) $(OBJFILES) $(CFLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

CLEAN:
	rm $(OBJFILES) $(EXE)

INSTALL:
	cp ./safeBuffer /usr/bin/safeBuffer