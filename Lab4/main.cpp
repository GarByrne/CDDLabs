// Author: Garry Byrne
// Created: 18th October 2017
// Purpose: A reusable barrier class.


#include "Barrier.h"
#include <thread>
#include <vector>

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 
   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads
*/

/*! displays the first function in the barrier being executed */
void task(std::shared_ptr<Barrier> barrierObj){

  std::cout << "first " << std::endl;
  /*! this calls the function in the barrier to wait on all of the threads before moving on*/
  barrierObj->waitForAll();
  std::cout << "second" << std::endl;
  barrierObj->waitForAll();
  std::cout << "third" << std::endl;
  barrierObj->waitForAll();
  std::cout << "fourth" << std::endl;
}

int main(void){

  /*!< An array of threads*/
  std::vector<std::thread> threadArray(5);
  /*!< Pointer to barrier object*/
  std::shared_ptr<Barrier> barrierObj( new Barrier);
  /*! sets the count in the barrier class*/
  barrierObj->setCount(threadArray.size());

  for(int i=0; i < threadArray.size(); i++){
    threadArray[i]=std::thread(task,barrierObj);
  }

  for(int i = 0; i < threadArray.size(); i++){
    threadArray[i].join();
  }
  
  return 0;
}
