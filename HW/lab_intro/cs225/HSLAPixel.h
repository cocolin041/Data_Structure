/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#ifndef CS225_HSLAPIXEL_H_
#define CS225_HSLAPIXEL_H_

#include <iostream>
#include <sstream>

namespace cs225 {
  class HSLAPixel {
    public: 
      double h, s, l, a;
      HSLAPixel();
      HSLAPixel(double h1, double s1, double l1);
      HSLAPixel(double h1, double s1, double l1, double a1);
  };
};

#endif
