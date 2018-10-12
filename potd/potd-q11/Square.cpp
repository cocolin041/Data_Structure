#include <iostream>
#include <string>
using namespace std;

#include "Square.h"

Square::Square() {
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}

void Square::setName(string newName) {
  name = newName;
}

void Square::setLength(double newVal) {
  *lengthptr = newVal;
}

string Square::getName() const {
  return name;
}

double Square::getLength() const {
  return *lengthptr;
}

Square::Square(const Square & other) {
    name = other.getName();
    lengthptr = new double;
    *lengthptr = other.getLength();
}

Square::~Square() {
    delete lengthptr;
}

Square Square::operator+(const Square & other) {
  Square sq;
  sq.setName(this->getName() + other.getName());
  sq.setLength(this->getLength() + other.getLength());
  return sq;
}

Square & Square::operator=(const Square & other) {
  this->setName(other.name);
  lengthptr = new double;
  *lengthptr = other.getLength();
  this->setLength(*lengthptr);
  return *this;
}