#include "Node.h"
#include <iostream>

using namespace std;

Node *listSymmetricDifference(Node *first, Node *second) {
  Node *intersect = nullptr;
  Node *old_first = first;
  Node *old_second = second;
  Node *new_intersect = nullptr;
  Node *old_intersect = nullptr;
  bool equal = false;
  bool repeat = false;

//from second
  while (second != NULL) {
		while (first != NULL) {
			if (second->data_ == first->data_) {
        equal = true;
			}
			if (first->next_ != nullptr) {
				first = first->next_;
			} else {
				first = nullptr;
			}
		}
    if (equal == false) {
      if (intersect == nullptr) {
        intersect = new Node();
        intersect->data_ = second->data_;
        intersect->next_ = NULL;
        old_intersect = intersect;
      } else {
        while (intersect->next_ != NULL) {
          if (intersect->data_ == second->data_) {
            repeat = true;
          }
          intersect = intersect->next_;
        }
        if (intersect->data_ == second->data_) {
          repeat = true;
        }
        if (repeat == false) {
          new_intersect = new Node();
          new_intersect->data_ = second->data_;
          new_intersect->next_ = NULL;
          intersect->next_ = new_intersect;
        }
        repeat = false;
        intersect = old_intersect;
      }
    }
    equal = false;
		first = old_first;
		if (second->next_ != nullptr) {
			second = second->next_;
		} else {
			second = nullptr;
		}
  }
  first = old_first;
  second = old_second;
  //from first
  while (first != NULL) {
		while (second != NULL) {
      std::cout << "second is " << second->data_ <<
      " first is " << first->data_ << std::endl;
			if (second->data_ == first->data_) {
        equal = true;
			}
			if (second->next_ != nullptr) {
				second = second->next_;
			} else {
				second = nullptr;
			}
		}
    if (equal == false) {
      if (intersect == nullptr) {
        intersect = new Node();
        intersect->data_ = first->data_;
        intersect->next_ = NULL;
        old_intersect = intersect;
      } else {
        while (intersect->next_ != NULL) {
          if (intersect->data_ == first->data_) {
            repeat = true;
          }
          intersect = intersect->next_;
        }
        if (intersect->data_ == first->data_) {
          repeat = true;
        }
        if (repeat == false) {
          new_intersect = new Node();
          new_intersect->data_ = first->data_;
          new_intersect->next_ = NULL;
          intersect->next_ = new_intersect;
        }
        repeat = false;
        intersect = old_intersect;
      }
    }
    equal = false;
		second = old_second;
		if (first->next_ != nullptr) {
			first = first->next_;
		} else {
			first = nullptr;
		}
  }
	
	if (old_intersect != nullptr) {
		intersect = old_intersect;
		return intersect;
	} else {
		intersect = NULL;
		old_intersect = NULL;
		delete intersect;
		delete old_intersect;
		return NULL;
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
