CC=g++
CFLAGS= -std=c++11 -pthread -I.
DOXYGEN = doxygen
INDEX_SRC = docs/html/index.html
INDEX = firefox $(INDEX_SRC)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: Semaphore.o SafeBuffer.o main.o
	$(CC) -o ProducerConsumer Semaphore.o SafeBuffer.o  main.o $(CFLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

DOC: 
	$(DOXYGEN) Doxyfile
	$(INDEX)
DOC: ALL

CLEAN:
	rm *.o
