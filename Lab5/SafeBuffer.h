#ifndef SAFEBUFFER_H
#define SAFEBUFFER_H

// Author: Garry Byrne
// Created: 18th October 2017
// Purpose: create Producer Consumer relationship

#include <mutex>
#include "Semaphore.h"
#include <queue>

/*!  Class used to provide safe access to a shared buffer.*/
class SafeBuffer {
 public:
  std::shared_ptr<Semaphore> mutex;
  std::shared_ptr<Semaphore> items;
  std::shared_ptr<Semaphore> spaces;
  std::queue<char> safeBuffer;
  SafeBuffer();
  void Add(char);
  char Remove();
};

#endif //  SAFEBUFFER_H_
