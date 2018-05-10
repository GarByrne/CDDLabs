#Garry Byrne 06/10/17

CC=g++
CFLAGS= -std=c++11 -pthread -I.
DOXYGEN = doxygen
INDEX_SRC = docs/html/index.html
INDEX = firefox $(INDEX_SRC)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: Semaphore.o  signal.o
	$(CC) -o signal Semaphore.o signal.o $(CFLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

DOC: 
	$(DOXYGEN) Doxyfile
	$(INDEX)
DOC: ALL

CLEAN:
	rm *.o
