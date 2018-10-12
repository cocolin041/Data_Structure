#include "Queue.h"

Queue::Queue() {
  index = 0;
  int q[0];
  point_front = 0;
}

// `int size()` - returns the number of elements in the stack (0 if empty)
int Queue::size() const {
  return index;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
  if (index > 0) {
    return false;
  } else {
    return true;
  }
}

// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value) {
  q[index] = value;
  index += 1;
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
  int front = 0;
  if (index > 0) {
    front = q[point_front];
    point_front += 1;
    index -= 1;
    return front;
  } else {
    return -1;
  }
}
