/* SafeBuffer.h --- 
 * 
 * Filename: SafeBuffer.h
 * Description: 
 * Author: Joseph
 * Maintainer: 
 * Created: Tue Jan  8 12:30:23 2019 (+0000)
 * Version: 
 * Package-Requires: ()
* Last-Updated: Mon Oct 9 12:40:00 2023 (+0000)
 *           By: Alex Paquette
 *     Update #: 1
 * URL: 
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change Log:
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */
#include "Semaphore.h"
#include "Event.h"
#include <iostream>
#include <vector>

/*! \class SafeBuffer
    \brief A Buffer Implementation

   Uses C++11 features to implement a Buffer class that contains an array of events, as well as Semaphores to controll access
   to the events array. It contains put() and get() methods to add and remove events from the array.

*/
class SafeBuffer{
    private:
        int producerPosition;
        int consumerPosition;
        std::vector<std::shared_ptr<Event>> events;
        std::shared_ptr<Semaphore> mutex;
        std::shared_ptr<Semaphore> items;
        std::shared_ptr<Semaphore> spaces;
        std::shared_ptr<Semaphore> producerPositionSem;
        std::shared_ptr<Semaphore> consumerPositionSem;
        void UpdatePosition();

    public:
        SafeBuffer(int size);
        void put(std::shared_ptr<Event> e);
        void get();
};


/* SafeBuffer.h ends here */
