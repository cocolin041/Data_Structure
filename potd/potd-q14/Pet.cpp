// Pet.cpp
#include "Pet.h"

Pet::Pet() {
  type_ = "cat";
  food_ = "fish";
  name_ = "Fluffy";
  owner_name_ = "Cinda";
}
Pet::Pet(string type, string food, string name, string owner_name) {
  type_ = type;
  food_ = food;
  name_ = name;
  owner_name_ = owner_name;
}
void Pet::setFood(string nu_food) {
    food_ = nu_food;
}

string Pet::getFood() {
    return food_;
}
void Pet::setName(string name) {
    name_ = name;
}

string Pet::getName() {
    return name_;
}

void Pet::setType(string nu_type) {
    type_ = nu_type;
}

string Pet::getType() {
    return type_;
}
void Pet::setOwnerName(string owner_name) {
    owner_name_ = owner_name;
}
string Pet::getOwnerName() {
  return owner_name_;
}

string Pet::print() {
    return "My name is " + name_;
};