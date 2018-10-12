/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#include "HSLAPixel.h"
#include <cmath>
#include <iostream>
using namespace std;

namespace cs225 {
  HSLAPixel::HSLAPixel(){
    a = 1;
    l = 1;
  };
  HSLAPixel::HSLAPixel(double h1, double s1, double l1){
    h = h1;
    s = s1;
    l = l1;
    a = 1;
  };
  HSLAPixel::HSLAPixel(double h1, double s1, double l1, double a1){
    h = h1;
    s = s1;
    l = l1;
    a = a1;
  };
}
