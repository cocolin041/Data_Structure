#include <string>
#include "pet.h"

using namespace std;

// Put your constructor code here!

// default constructor: no parameter, initialize class value of default value
Pet::Pet() { 
  name = "Rover";
  birth_year = 2018;
  type = "dog";
  owner_name = "Wade";
}
//custom constructor
Pet::Pet(string newName_pet, int newBY, string newType, string newName_owner) { 
  name = newName_pet;
  birth_year = newBY;
  type = newType;
  owner_name = newName_owner;
}

void Pet::setName(string newName) {
  name = newName;
}

void Pet::setBY(int newBY) {
  birth_year = newBY;
}

void Pet::setType(string newType) {
  type = newType;
}

void Pet::setOwnerName(string newName) {
  owner_name = newName;
}

string Pet::getName() {
  return name;
}

int Pet::getBY() {
  return birth_year;
}

string Pet::getType() {
  return type;
}

string Pet::getOwnerName() {
  return owner_name;
}
