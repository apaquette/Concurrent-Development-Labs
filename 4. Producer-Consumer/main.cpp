#include "SafeBuffer.h"
#include <iostream>
#include <thread>
#include <vector>

/*! \file main.cpp
    \brief main file for demonstrating producers and consumers
*/

static const int num_threads = 50;
const int size = 5;

/*! 
    \fn void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops)
    \brief Creates events and adds them to buffer
    \param theBuffer SafeBuffer that contains shared events
    \param numLoops Number of times loops through the buffer
*/
void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){
  for(int i = 0; i < numLoops; ++i){
    theBuffer->put(std::make_shared<Event>());
  }
}

/*! 
    \fn void consumer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops)
    \brief Consumes events from buffer
    \param theBuffer SafeBuffer that contains shared events
    \param numLoops Number of times loops through the buffer
*/
void consumer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){
  for(int i = 0; i < numLoops; ++i){
    theBuffer->get();
  }
}

int main(void){
  std::vector<std::thread> producers(num_threads);
  std::vector<std::thread> consumers(num_threads);
  std::shared_ptr<SafeBuffer> aBuffer = std::make_shared<SafeBuffer>(size);
  int numLoops = 10;
  /**< Launch the threads  */
  for(int i = 0; i < num_threads; ++i){
    producers[i] = std::thread(producer, aBuffer, numLoops);
  }
  for(int i = 0; i < num_threads; ++i){
    consumers[i] = std::thread(consumer, aBuffer, numLoops);
  }

  /**< Join the threads with the main thread */
  for (auto& v :producers){
      v.join();
  }

  for (auto& v :consumers){
      v.join();
  }
  return 0;
}