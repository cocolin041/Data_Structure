#include "TreeNode.h"
#include <iostream>

bool isHeightBalanced(TreeNode* root) {
  // your code here
  int balance_factor = computeHeight(root->right_) - computeHeight(root->left_);
  if (balance_factor <= 1 && balance_factor >= -1) {
    return true;
  } else {
    return false; 
  }
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

int computeHeight(TreeNode* root) {
  int height = 0;
  int height_L = 0;
  int height_R = 0;
  if (root == NULL) {
    return -1;
  }
  if (root->left_ == NULL && root->right_ == NULL) {
    return height;
  } else {
    if (root->left_ != NULL) {
      height_L = computeHeight(root->left_);
    }
    if (root->right_ != NULL) {
      height_R = computeHeight(root->right_);
    }
    if (height_L > height_R) {
      return (height_L + 1);
    } else {
      return (height_R + 1);
    }
  }
}