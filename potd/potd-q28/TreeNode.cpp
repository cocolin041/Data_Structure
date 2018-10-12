#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
  int left_height = 0;
  int right_height = 0;
  
  if (this != NULL) {
    TreeNode *curr = this;
    if (this->left_ == NULL && this->right_ == NULL) {
      return 0;
    }
    while (curr->left_ != NULL | curr->right_ != NULL) {
      while (curr->left_ != NULL) {
        left_height += 1;
        curr = curr->left_;
      }
      while (curr->right_ != NULL) {
        left_height += 1;
        curr = curr->right_;
      }
    }
    curr = this;
    while (curr->left_ != NULL | curr->right_ != NULL) {
      while (curr->right_ != NULL) {
        right_height += 1;
        curr = curr->right_;
      }
      while (curr->left_ != NULL) {
        right_height += 1;
        curr = curr->left_;
      }
    }
    return std::max(left_height, right_height);
  } else {
    return -1;
  }
}