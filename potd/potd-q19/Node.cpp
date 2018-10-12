#include "Node.h"
#include "iostream"
using namespace std;

Node *listUnion(Node *first, Node *second) {
  // your code here
  Node *node = new Node(*first);
  Node *head = first;
  Node *temp = head;
  bool repeat = false;
  while (first->next_ != NULL) {
    temp = head;
    first = first->next_;
    while (temp != NULL) {
      if (temp->data_ == first->data_) {
        repeat = true;
      }
      temp = temp->next_;
    }
    if (!repeat) {
      node->next_ = first;
      node = node->next_;
    }
    repeat = false;
  }
  //for the last first node
  temp = head;
  while (temp != NULL) {
    if (temp->data_ == first->data_) {
      repeat = true;
    }
    temp = temp->next_;
  }
  temp = head;
  if (!repeat) {
      node->next_ = first;
      node = node->next_; 
  }
  repeat = false;

  //start the second
  if (second != NULL) {
    while (temp != NULL) {
      if (temp->data_ == second->data_) {
        repeat = true;
      }
      temp = temp->next_;
    }
    temp = head;
    if (!repeat) {
      node->next_ = second;
      node = node->next_;
    }
    repeat = false;
    while (second->next_ != NULL) {
      second = second->next_;
      while (temp != NULL) {
        if (temp->data_ == second->data_) {
          repeat = true;
        }
        temp = temp->next_;
      }
      temp = head;
      if (!repeat) {
        node->next_ = second;
        node = node->next_;
      }
      repeat = false;
    }
  }
  // node = head;
  // while (node != NULL) {
  //   std::cout << node->data_ << std::endl;
  //   node = node->next_;
  // }
  return head;
  return NULL;
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
