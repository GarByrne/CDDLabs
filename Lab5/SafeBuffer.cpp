// Author: Garry Byrne
// Created: 18th October 2017
// Purpose: create Producer Consumer relationship

/*! \class SafeBuffer
    \brief An Implementation of a safe buffer class

*/

#include "SafeBuffer.h"
#include <iostream>

/**
   Constructor, spaces provides a finite buffer size
 */

SafeBuffer::SafeBuffer() {
  items = std::make_shared<Semaphore>(0);
  mutex = std::make_shared<Semaphore>(1);
  spaces = std::make_shared<Semaphore>(100);
}

/**
   Add first checks for available space in the buffer, it then puts a mutex on the queue(safeBuffer) and adds the character. It then releases the mutex and signals items, to indicate that the consumer can take something.
 */

void SafeBuffer::Add(char c) {
  spaces->Wait();
  mutex->Wait();
  safeBuffer.push(c);
  mutex->Signal();
  items->Signal();
}

/**
   Remove first checks if there are items to be consumed, it then claims the mutex and removes an item. Finally it releases the mutex and adds a space to the buffer.
 */

char SafeBuffer::Remove() {
  char c;
  items->Wait();
  mutex->Wait();
  c = safeBuffer.front();
  safeBuffer.pop();
  mutex->Signal();
  spaces->Signal();
  return c;
}
