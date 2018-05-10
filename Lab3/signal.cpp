//Author: Garry Byrne
//Program name: signal
//Purpose: create an example of a mutual exclusion
#include "Semaphore.h"
#include <iostream>
#include <thread>

/*! \class Signal
    \brief An Implementation of a mutex lock Using Semaphores 
   Uses C++11 features such as mutex and condition variables to implement a mutex lock using Semaphores
*/

/*! global count for checkIn() function*/
int num = 0;


/*! Only allows one thread to access the global variable 'count' at a time*/
void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout << "Count " << num <<std::endl;
  num++;
  theSemaphore->Signal();
}

int main(void){

  std::thread threadOne, threadTwo, threadThree;
  std::shared_ptr<Semaphore> sem( new Semaphore(1));
  /**< Launch the threads  */
  threadOne=std::thread(taskOne,sem);
  threadTwo=std::thread(taskOne,sem);
  threadThree=std::thread(taskOne,sem);
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  return 0;
}
