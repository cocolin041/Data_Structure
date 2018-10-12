#pragma once
#include <iostream>
#include "Base.h"
using namespace std;

class Derived : public Base {
  public:
    Derived();
    string foo();
    string bar();
    virtual ~Derived();
};