#include <vector>
#include "Hash.h"

void doubleHashInput(std::vector<int> &v, int elem){
	//your code here
  int firstIndex = firstHash(elem, v.size());
  int secondIndex = secondHash(elem);
  // int i = 1;
  while (v[firstIndex] != -1) {
    firstIndex = (firstIndex + secondIndex) % (int)v.size();
    // i += 1;
  }
  if (v[firstIndex] == -1) {
    v[firstIndex] = elem;
  }
}

//make a hash function called firstHash
int firstHash(int elem, int length) {
  return (elem * 4) % length;
}
//make a second function called secondHash
int secondHash(int elem) {
  return 3 - elem % 3;
}