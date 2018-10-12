#ifndef _STACK_H
#define _STACK_H

#include <cstddef>

class Stack {
public:
  Stack();
  int size() const;
  bool isEmpty() const;
  void push(int value);
  int pop();
  int index;
  int s[];
};

#endif
