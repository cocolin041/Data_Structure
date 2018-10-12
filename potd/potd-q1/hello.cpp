/* Your code here! */
#include <iostream>
#include "hello.h"
using namespace std;

int your_age = 24;
std::string your_name = "Coco"; //single quote is only for char
//char your_name = 'Coco'; //char can only be one letter


std::string hello() {
  return ("Hello world! My name is " + your_name + " and I am " + std::to_string(your_age) + " years old.");
  //  greeting;
}