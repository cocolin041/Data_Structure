#include "potd.h"
#include <iostream>

// Your code here!
double sum(vector<double>::iterator start, vector<double>::iterator end) {
  double total = 0;
  for (vector<double>::iterator it = start; it != end; it++) {
    total += *it;
  }
  return total;
}
vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end) {
  vector<double>::iterator max = start;
  for (vector<double>::iterator it = start; it != end; it++) {
    if (*max < *it) {
      max = it;
    }
  }
  return max;
}
void sort_vector(vector<double>::iterator start, vector<double>::iterator end) {
  std::vector<double> unsorted;
  std::vector<double> sorted;

  for (vector<double>::iterator it = start; it != end; it++) {
    unsorted.push_back(*it);
  }
  while (unsorted.empty() != true) {
    vector<double>::iterator max_position = max_iter(unsorted.begin(), unsorted.end());
    sorted.push_back(*max_position);
    unsorted.erase(max_position);
  }
  for (vector<double>::iterator it = start; it != end; it++) {
    *it = *sorted.begin();
    sorted.erase(sorted.begin());
  }
}