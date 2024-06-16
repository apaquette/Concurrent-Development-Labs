#include "Semaphore.h"
#include <iostream>

/*! \class Barrier
    \brief A Barrier Implementation

   Uses C++11 features such as mutex and condition variables to implement a Barrier class using Semaphores

*/
class Barrier
{
private:
  int count;
  int threadNum;
  bool condition;
  std::shared_ptr<Semaphore> mutex;
  std::shared_ptr<Semaphore> innerLock;
  std::shared_ptr<Semaphore> outerLock;


public:
  ~Barrier();
  Barrier(int count);
  int getCount();
  void waitForAll();
};
