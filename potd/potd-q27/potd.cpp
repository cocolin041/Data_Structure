// Your code here
#include "potd.h"

string getFortune(const string &s) {
  if (s.length() > 0) {
    if (s.substr(0, s.find(" ")).length() == 1) {
      return "As you wish!";
    }
    if (s.substr(0, s.find(" ")).length() == 2) {
      return "I dont't know!";
    }
    if (s.substr(0, s.find(" ")).length() == 3) {
      return "Do, or do not. There is no try.";
    }
    if (s.substr(0, s.find(" ")).length() == 4) {
      return "This fortune intentionally left blank.";
    }
    if (s.substr(0, s.find(" ")).length() == 5) {
      return "Amor Fati!";
    }
  }
}
