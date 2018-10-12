#include "Stack.h"

Stack::Stack() {
  index = 0;
  int s[0];
}

// `int size()` - returns the number of elements in the stack (0 if empty)
int Stack::size() const {
  return index;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Stack::isEmpty() const {
  if (index > 0) {
    return false;
  } else {
    return true;
  }
}

// `void push(int val)` - pushes an item to the stack in O(1) time
void Stack::push(int value) {
  s[index] = value;
  index += 1;
}

// `int pop()` - removes an item off the stack and returns the value in O(1) time
int Stack::pop() {
  int top = 0;
  if (index > 0) {
    top = s[index - 1];
    index -= 1;
    return top;
  } else {
    return -1;
  }
}
