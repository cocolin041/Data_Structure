// your code here
#include "Food.h"
#include "q5.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;

int main() {
  Food food;
  food.set_quantity(5);
  Food *copy_of_food;
  copy_of_food = &food;
  cout << food.get_quantity() << endl;

  increase_quantity(copy_of_food);
  cout << food.get_quantity() << endl;
}