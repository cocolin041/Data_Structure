/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 */

#pragma once
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
  class Red {
    public:
      double h, s, l, a;
      Red();
  };
  class Blue {
    public:
      double h, s, l, a;
      Blue();
  };
  class White {
    public:
      double s, l, a;
      White();
  };
  class Green {
    public:
      double h, s, l, a;
      Green();
  };
  class Purple {
    public:
      double h, s, l, a;
      Purple();
  };
  class Orange {
    public:
      double h, s, l, a;
      Orange();
  };
  class Yellow {
    public:
      double h, s, l, a;
      Yellow();
  };
  class Light_blue {
    public:
      double h, s, l, a;
      Light_blue();
  };
  
};

#endif
