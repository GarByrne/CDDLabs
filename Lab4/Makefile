#Author: Garry Byrne
#Created: 18th October 2017

CC=g++
CFLAGS= -std=c++11 -pthread
CFiles= Semaphore.cpp Barrier.cpp

SIMPLE: $(CFiles)
		$(CC) $(CFLAGS) -o barrier $(CFiles) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: SIMPLE

Clean:
			 rm *.o
