#include <vector>
#include "BTreeNode.h"
#include <iostream>


BTreeNode* find(BTreeNode* root, int key) {
  // Your Code Here
  int i;
  for (i = 0; i < (int)root->elements_.size() && key > root->elements_[i]; i++) {}
  if (i < (int)root->elements_.size() && key == root->elements_[i]) {
    return root;
  }
  if (root->is_leaf_ == true) {
    return NULL;
  } else {
    BTreeNode* nextChild = root->children_[i];
    return find(nextChild, key);
  }
}
