// Author: Garry Byrne
// Created: 18th October 2017
// Purpose: A reusable barrier class.

#include "Semaphore.h"
#include <iostream>
#include <thread>

using namespace std;
int count = 0, threadCount = 0, barrierLimit = 3,i = 0,testAmount = 10;

void taskOne(shared_ptr<Semaphore> Mutex,shared_ptr<Semaphore> BarrierA,shared_ptr<Semaphore> BarrierB)
  {
    threadCount++;
    cout << "Thread " << threadCount << " before Barrier" << endl;
    Mutex->Wait();
    count++;
    if(count == barrierLimit)
      {
        BarrierB->Wait();
        BarrierA->Signal();
        threadCount = 0;
      }
    Mutex->Signal();
    BarrierA->Wait();
    BarrierA->Signal();
    threadCount++;

    cout << "Thread " << threadCount << " after Barrier" << endl;

    Mutex->Wait();
    count --;
    if(count == 0)
      {
        BarrierA->Wait();
        BarrierB->Signal();
      }
    Mutex->Signal();
    BarrierB->Wait();
    BarrierB->Signal();
  }

int main(void)
  {
    thread threadOne, threadTwo, threadThree;
    shared_ptr<Semaphore> Mutex(new Semaphore(1));
    shared_ptr<Semaphore> BarrierA(new Semaphore);
    shared_ptr<Semaphore> BarrierB(new Semaphore(1));

    while(i <= testAmount)
      {
        threadCount = 0;
        threadOne=thread(taskOne,Mutex,BarrierA,BarrierB);
        threadTwo=thread(taskOne,Mutex,BarrierA,BarrierB);
        threadThree=thread(taskOne,Mutex,BarrierA,BarrierB);
        i++;

        threadOne.join();
        threadTwo.join();
        threadThree.join();
        cout << endl << endl;
      }
    return 0;
}
