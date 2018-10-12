#include "Node.h"
#include <iostream>
using namespace std;

void mergeList(Node *first, Node *second) {
  // your code here!
  Node *oldhead_1 = first;
  Node *oldhead_2 = second;
  Node *curr_1 = first;
  Node *curr_2 = second;
  Node *next_1 = NULL;
  Node *next_2 = NULL;
  if (first != NULL && second != NULL) {
    int length_1 = 0;
    int length_2 = 0;

    while (first != NULL) {
      length_1 += 1;
      first = first->next_;
    }
    first = oldhead_1;
    while (second != NULL) {
      length_2 += 1;
      second = second->next_;
    }
    second = oldhead_2;

    if (length_1 <= length_2) {
      for (int i = 0; i < length_1 - 1; i++) {
        next_1 = curr_1->next_;
        next_2 = curr_2->next_;

        curr_1->next_ = curr_2;
        curr_2->next_ = next_1;

        curr_1 = next_1;
        curr_2 = next_2;
      }
      curr_1->next_ = curr_2;
    } else {
      for (int i = 0; i < length_2 - 1; i++) {
        next_1 = curr_1->next_;
        next_2 = curr_2->next_;

        curr_1->next_ = curr_2;
        curr_2->next_ = next_1;

        curr_1 = next_1;
        curr_2 = next_2;
      }
      next_1 = curr_1->next_;
      curr_1->next_ = curr_2;
      curr_2->next_ = next_1;
    }
  } 
  if (first == NULL) {
    first = second;
  }
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;

