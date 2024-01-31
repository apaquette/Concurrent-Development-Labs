// mandelbroit.cpp --- m
// 
// Filename: mandelbroit.cpp
// Description: 
// Author: Joseph
// Maintainer: 
// Created: Mon Feb  4 09:40:41 2019 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: Mon Feb  4 10:08:24 2019 (+0000)
//           By: Joseph
//     Update #: 18
// URL: 
// Doc URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change Log:
// 
// 
// 
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
// 
// 

// Code:

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <complex>      /* complex number data type */
#include <time.h>       /* time */
#include <limits>

/*! \file madelbroit.cpp
    \brief main file for demonstrating mandelbroit
*/

using namespace std ;

const int ROW=1000; /*! Number of rows */
const int COL=1000; /*! Number of columns */
const int DEPTH=10; /*! The depth */

/*!
  \fn int calc(complex<int> c, int depth)
  \brief Performs a calculation on a complex int based on a depth provided
  \param c The complex int
  \param depth The depth
  \return Returns the result of the calculation
*/
int calc(complex<int> c, int depth){
    int count=0;
    complex<int> z=0;
    for(int i=0;i<depth;++i){
      if (abs(z)>2.0){
        break;
      }
      z=z*z+c;
      count++;
    }
    return count;
}

/*!
  \fn void mandel( int p[ROW][COL], int depth)
  \brief Processes calculation on p array by depth
  
  Processes calculation on p array by depth. Uses pragma to collapse two loops into one, and run in parallel.

  \param p 2D array of ints
  \param depth The depth

*/
void mandel( int p[ROW][COL], int depth){
  #pragma omp parallel for collapse(2) //Alex: Collapses the two loops into a single loop, number two indicates how many loops should be collapsed
  for(int i=0;i<ROW;++i){
        for(int k=0;k<COL;++k){
	  p[i][k]=calc(complex<int>(i,k),depth);
	}
    }
}

int main(void){

  
  int myArray[ROW][COL];
  /* initialize random seed: */
  srand (time(NULL));
  
  clock_t begin = clock();
  mandel(myArray,DEPTH);
  clock_t end = clock();
  double timeSec = (end - begin) / static_cast<double>( CLOCKS_PER_SEC );
  std::cout << timeSec << std::endl;
}


// 
// mandelbroit.cpp ends here
