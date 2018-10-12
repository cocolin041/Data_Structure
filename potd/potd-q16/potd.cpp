#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node **head, Node *insert) {
  // your code here!
  if (*head == NULL) {
    *head = insert;
  } else {
    Node *prev = nullptr;
    Node *curr = nullptr;
    curr = *head;

    while (curr->next_ != NULL && insert->data_ > curr->data_) {
      prev = curr;
      curr = curr->next_;
    }
    if (curr->next_ == NULL) {  //add on the tail
      if (insert->data_ > curr->data_) {
        curr->next_ = insert;  
      } else {
        prev->next_ = insert;
        insert->next_ = curr;
      }
    }
    if (curr->next_ != NULL && insert->data_ < curr->data_) {
      if (insert->data_ < (*head)->data_) {
        insert->next_ = curr;
        *head = insert;
      } else {
        prev->next_ = insert;
        insert->next_ = curr;
      }
    }
  }
}
