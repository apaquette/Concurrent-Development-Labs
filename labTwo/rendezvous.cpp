#include "Semaphore.h"
#include <thread>
#include <vector>
#include <iostream>

/*! \file rendezvous.cpp
    \brief main file for demonstrating rendezvous
*/

/*! 
  \fn void task(std::shared_ptr<Semaphore> mutexSem,std::shared_ptr<Semaphore> barrierSem, std::shared_ptr<int> threadCount)
  \brief Displays the first function in the barrier being executed
  \param mutexSem Mutex used to wait for threadCount access
  \param barrierSem Barrier to indicate threadCount is released
  \param threadCount Number of threads that will run the task
*/
void task(std::shared_ptr<Semaphore> mutexSem,std::shared_ptr<Semaphore> barrierSem, std::shared_ptr<int> threadCount){
  std::cout << "first\n";
  mutexSem->Wait();
  if(--*threadCount == 0) {
    barrierSem->Signal();
  }
  mutexSem->Signal();

  barrierSem->Wait();
  barrierSem->Signal();
  std::cout << "second\n";
}


int main(void){
  std::shared_ptr<Semaphore> mutexSem = std::make_shared<Semaphore>(1);
  std::shared_ptr<Semaphore> barrierSem = std::make_shared<Semaphore>(0);
  std::shared_ptr<int> threadCount = std::make_shared<int>(5);

  /*!< An array of threads*/
  std::vector<std::thread> threadArray(*threadCount);
  /*!< Pointer to barrier object*/

  for(unsigned long int i=0; i < threadArray.size(); i++){
    threadArray[i]=std::thread(task,mutexSem,barrierSem,threadCount);
  }

  for(unsigned long int i = 0; i < threadArray.size(); i++){
    threadArray[i].join();
  }
  
  return 0;
}
