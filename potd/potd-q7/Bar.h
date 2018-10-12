// your code here
/*
A private member variable Foo * f_.
A constructor that takes a string.
A copy constructor.
A destructor.
An operator=.
A method string get_name() to return the name contained within f_.
*/
#pragma once
#include <iostream>
#include "Foo.h"

namespace potd {
  class Bar {
    public:
      Bar(string);
      Bar(const Bar & other); //copy ctor
      ~Bar();
      Bar & operator=(const Bar & other);
      string get_name();
    private:
      Foo * f_;
  };
}