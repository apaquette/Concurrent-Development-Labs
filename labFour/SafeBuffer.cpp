#include "SafeBuffer.h"

/*! \class SafeBuffer
    \brief A Buffer Implementation

   Uses C++11 features to implement a Buffer class that contains an array of events, as well as Semaphores to controll access
   to the events array. It contains put() and get() methods to add and remove events from the array.

*/


/*! 
    \fn SafeBuffer::SafeBuffer(int size)
    \brief Constructor for the Buffer Class with size
    \param size Size of the vector of events
*/
SafeBuffer::SafeBuffer(int size){
    producerPosition = 0;
    consumerPosition = 0;

    events = std::vector<std::shared_ptr<Event>>(size);

    spaces = std::make_shared<Semaphore>(size); //prevent from putting when buffer is full
    mutex = std::make_shared<Semaphore>(1); //control access to the buffer
    items = std::make_shared<Semaphore>(0); //blocks when the buffer is empty
    producerPositionSem = std::make_shared<Semaphore>(1);
    consumerPositionSem = std::make_shared<Semaphore>(1);
}


/*! 
    \fn void SafeBuffer::put(std::shared_ptr<Event> e)
    \brief Add an event to the buffer 
    \param e Event to be added to the buffer
*/
void SafeBuffer::put(std::shared_ptr<Event> e){
    spaces->Wait();
    mutex->Wait();

    producerPositionSem->Wait();

    events[producerPosition] = e;

    if(++producerPosition == events.size()){//if we reached the end of the list, go back to the start
        producerPosition = 0;
    }

    producerPositionSem->Signal();

    mutex->Signal();
    items->Signal();
}

/*! 
    \fn void SafeBuffer::get()
    \brief Remove an event from the buffer
*/
void SafeBuffer::get(){
    items->Wait();
    mutex->Wait();

    consumerPositionSem->Wait();

    events[consumerPosition]->consume();

    if(++consumerPosition == events.size()){//if we reached the end of the list, go back to the start
        consumerPosition = 0;
    }

    consumerPositionSem->Signal();

    mutex->Signal();
    spaces->Signal();
}