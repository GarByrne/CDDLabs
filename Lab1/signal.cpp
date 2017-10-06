#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> theSemaphore,  std::shared_ptr<Semaphore> sem2){
  std::cout <<"I ";
  std::cout << "must "<<std::endl;
  theSemaphore->Signal();
  sem2->Wait();
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> theSemaphore, std::shared_ptr<Semaphore> sem2){
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will "<<std::endl;
  sem2->Signal();
  theSemaphore->Wait();
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem,sem2);
  threadTwo=std::thread(taskOne,sem,sem2);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
