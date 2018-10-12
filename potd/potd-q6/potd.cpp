// your code here!
#include "potd.h"
#include <cmath>
#include <iostream>
using namespace std;
using std::cout;
using std::endl;

namespace potd {
  int *raise(int *arr) {
    int size = 1;
    for (int i = 0; arr[i] != -1; i++) {
      size +=1;
    }

    int *new_arr = new int[size];

    for (int i = 0; i < size; i++) {
      if (i == size - 1 | i == size - 2) {
        new_arr[i] = arr[i];
      } else {
        new_arr[i] = pow(arr[i], arr[i+1]); 
      }
    }
    return new_arr;
  }
}