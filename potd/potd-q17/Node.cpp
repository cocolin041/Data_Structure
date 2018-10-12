#include "Node.h"
#include <iostream>
using namespace std;

void sortList(Node **head) {
  // your code here!
  if (*head != NULL) {
  if ((*head)->next_ != NULL) {
    int cout = 0;
    Node *oldhead = *head;

    while (*head != NULL) {
      cout += 1;
      *head = (*head)->next_;
    }
    *head = oldhead;
    Node *prev = NULL;
    Node *curr = NULL;
    Node *next = NULL;
    Node *newhead = *head;

    if (cout > 4) {
      for (int j = 0; j < cout / 2; j++) {
        prev = NULL;
        curr = *head;
        for (int i = 0; i < cout - 1; i++) {
          if (curr->data_ > curr->next_->data_) {
            next = curr->next_;
            curr->next_ = next->next_;
            next->next_ = curr;
            if (prev != NULL) {
              prev->next_ = next;
              prev = next;
              curr = curr;
            } else {
              prev = next;
              curr = curr;
            }
            if (newhead == NULL | newhead->data_ > next->data_) {
              newhead = next;
            }
          } else {
            prev = curr;
            curr = curr->next_;
          }
        }   
      }
      *head = oldhead;
      if (oldhead->data_ > newhead->data_) {
        *head = newhead;  
      } else {
        *head = oldhead;
      }
    } else {
      if ((*head)->data_ > (*head)->next_->data_) {
        next = (*head)->next_;
        next->next_ = *head;
        (*head)->next_ = NULL;
        *head = next;
      }
    }
  }
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

