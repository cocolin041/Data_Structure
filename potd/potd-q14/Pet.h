// Pet.h
#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Animal.h"

class Pet : public Animal {
  public: 
    Pet();
    Pet(string type, string food, string name, string owner_name);
    void setFood(string nu_food);
    string getFood();
    void setType(string nu_type);
    string getType();
    void setName(string name);
    string getName();
    void setOwnerName(string owner_name);
    string getOwnerName();
    string print();
  private:
    string owner_name_;
    string name_;
    string type_;

};