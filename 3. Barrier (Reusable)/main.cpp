#include "Barrier.h"
#include <thread>
#include <vector>

/*! \file main.cpp
    \brief main file for demonstrating Barriers
*/

/*! 
  \fn void task(std::shared_ptr<Barrier> barrierObj)
  \brief Displays the first function in the barrier being executed 
  \param barrierObj Barrier object used to wait for other threads to catch up
*/
void task(std::shared_ptr<Barrier> barrierObj){
  for(int i = 0; i < 5; ++i){
    std::cout << "first\n";
    barrierObj->waitForAll();
    std::cout << "second\n";
    barrierObj->waitForAll();
  }
}

int main(void){
  /*!< An array of threads*/
  int threadCount = 5;
  std::vector<std::thread> threadArray(threadCount);
  /*!< Pointer to barrier object*/
  std::shared_ptr<Barrier> barrierObj(new Barrier(threadCount));
  for(unsigned long int i=0; i < threadArray.size(); ++i){
    threadArray[i]=std::thread(task,barrierObj);
  }
  for(unsigned long int i = 0; i < threadArray.size(); ++i){
    threadArray[i].join();
  }
  return 0;
}
