#include "Event.h"


/*! \class Event
    \brief An class representing an Event

   A simple event class used to represent events for simulation purposes. Contains
   a character value and a consume() method that will display the character value in uppercase.

*/

/*! 
    \fn Event::Event()
    \brief Parameterless constructor for the Event Class. The constructor generates a random lower case letter then outputs that letter
*/
Event::Event(){
    value = 'a' + rand()%26;
    printf("%c\n", value);
}

/*! 
    \fn void Event::consume()
    \brief Consume method that outputs the character value of the event in upper case
*/
void Event::consume(){
    printf("%c\n", toupper(value));
}