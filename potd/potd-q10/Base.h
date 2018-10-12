#pragma once
#include <iostream>
using namespace std;

class Base {
  public:
    Base();
    string foo();
    virtual string bar();
    virtual ~Base();
};