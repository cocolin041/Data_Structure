// Your code here
#include <iostream>
using namespace std;
using std::string;

class Food {
  public:
    Food();
    string get_name();
    void set_name(string name);
    int get_quantity();
    void set_quantity(int quantity);
  private:
    string name_;
    int quantity_;
};