// Your code here!
#include "Thing.h"
#include <iostream>

namespace potd {
  Thing::Thing(int size) {
    props_max_ = size;
    properties_ = new std::string[props_max_];
    values_ = new std::string[props_max_];
  }
  void Thing::_copy(const Thing & other) {
    props_max_ = other.props_max_;
    properties_ = new std::string[props_max_];
    values_ = new std::string[props_max_];

    for (int i = 0; i < props_max_; i++) {
      properties_[i] = other.properties_[i];
      values_[i] = other.values_[i];
    }

  }
  Thing::Thing(const Thing & other) {
    _copy(other);
  }
  
  void Thing::_destroy() {
    delete [] properties_;
    delete [] values_;
  }
  Thing::~Thing() {
    _destroy();
  }

  Thing & Thing::operator=(const Thing & other) {
    props_max_ = other.props_max_;
    for (int i = 0; i < props_max_; i++) {
      properties_[i] = other.properties_[i];
      values_[i] = other.values_[i];
    }
    return *this;
  }
  int Thing::set_property(std::string name,std::string value) {
      for (int i = 0; i < props_max_; i++) {
        if (properties_[i].size() == 0) {
          properties_[i] = name;
          values_[i]= value;
          return i;
        } else if (properties_[i] == name) {
          values_[i]= value;
          return i;
        }
      }
    return -1;
  }
  std::string Thing::get_property(std::string name) {
    for (int i = 0; i < props_max_; i++) {
      if (properties_[i] == name) {
        return values_[i];
      }
    }
    return "";
  }
}