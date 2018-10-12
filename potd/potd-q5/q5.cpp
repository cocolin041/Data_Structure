// your code here
#include "Food.h"
#include "q5.h"

void increase_quantity(Food * food){
  int Q = food->get_quantity();
  Q = Q + 1;
  food->set_quantity(Q);
}