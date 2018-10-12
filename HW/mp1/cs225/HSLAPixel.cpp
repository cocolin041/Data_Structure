/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
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
  Red::Red(){
    h = 360;
    s = 1;
    l = 0.5;
    a = 1;
  };
  Blue::Blue(){
    h = 228;
    s = 1;
    l = 0.28;
    a = 1;
  };
  White::White(){
    s = 1;
    l = 1;
    a = 1;
  };
  Yellow::Yellow(){
    h = 58;
    s = 1;
    l = 0.5;
    a = 1;
  };
  Green::Green(){
    h = 113;
    s = 1;
    l = 0.36;
    a = 1;
  };
  Purple::Purple(){
    h = 276;
    s = 1;
    l = 0.36;
    a = 1;
  };
  Orange::Orange(){
    h = 29;
    s = 1;
    l = 0.5;
    a = 1;
  };
  Light_blue::Light_blue(){
    h = 197;
    s = 1;
    l = 0.5;
    a = 1;
  };
}

