#include "Node.h"
#include <iostream>

using namespace std;

Node *listIntersection(Node *first, Node *second) {
  // your code here
	Node *intersect = nullptr;
	Node *old_first = first;
	Node *new_intersect = nullptr;
	Node *old_intersect = nullptr;

  while (second != NULL) {
		while (first != NULL) {
			if (second->data_ == first->data_) {
				if (intersect == nullptr) {
					std::cout << "hello" << std::endl;
					intersect = second;
					intersect->next_ = NULL;
					old_intersect = intersect;
				} else {
					while (intersect != NULL) {
						std::cout << second->data_ << std::endl;
						std::cout << intersect->data_ << std::endl;
						if (intersect->data_ != second->data_) {
							std::cout << "hello1" << std::endl;
							new_intersect = second;
							new_intersect->next_ = NULL;
							intersect->next_ = new_intersect;
						}
						if (intersect->next_ != NULL) {
							intersect = intersect->next_;
						} else {
							intersect = NULL;
						}
					}
					intersect = old_intersect;
				}
			}
			if (first->next_ != nullptr) {
				first = first->next_;
			} else {
				first = nullptr;
			}
		}
		first = old_first;
		if (second->next_ != nullptr) {
			second = second->next_;
		} else {
			second = nullptr;
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
