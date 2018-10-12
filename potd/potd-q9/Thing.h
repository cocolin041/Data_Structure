#ifndef THING_H
#define THING_H

#include <string>

namespace potd {
  class Thing {
  public:
    Thing(int size);
    Thing(const Thing & other);  //rule of three
    Thing & operator=(const Thing &); //rule of three
    ~Thing();  //rule of three

    int set_property(std::string name,std::string value);
    std::string get_property(std::string name);

  private:

    void _copy(const Thing & other);
    void _destroy();

    std::string *properties_; //containing the names of the properties
    std::string *values_; //containing the values of the properties
    int props_ct_;  //count how many properties we have
    int props_max_; //return the maximum number or properties
  };
}
#endif
