#include "TreeNode.h"
#include <iostream>

TreeNode* findLastUnbalanced(TreeNode* root) {
  TreeNode* left_unbalance = nullptr;
  TreeNode* right_unbalance = nullptr;
  TreeNode* old_root = root;

  if (root == nullptr || isHeightBalanced(root) == true) {
    return nullptr;
  }
  if (root->left_ != nullptr) {
    left_unbalance = findLastUnbalanced(root->left_);
  }
  if (root->right_ != nullptr) {
    right_unbalance = findLastUnbalanced(root->right_);
  }
  //both left and right are balanced => check if ourself is balanced
  if (left_unbalance == nullptr && right_unbalance == nullptr) {
    if (isHeightBalanced(root) == true) {
      return nullptr;
    }
    else {
      return root;
    }
  }
  //one of the left or right is unbalanced
  else if (left_unbalance != nullptr && right_unbalance != nullptr) {
    if (computeHeight(old_root) - computeHeight(left_unbalance) >= computeHeight(old_root) - computeHeight(right_unbalance)) {
      return findLastUnbalanced(left_unbalance);
    } else {
      return findLastUnbalanced(right_unbalance);
    }
  }
  //both of left and right are unbalanced
  else {
    if (left_unbalance != nullptr) {
      return left_unbalance;
    } else {
      return right_unbalance;
    }
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
  int height_L = -1;
  int height_R = -1;

  if (root == NULL) {
    return -1;
  }
  else {
    if (root->left_ != NULL) {
      height_L = computeHeight(root->left_);
    }
    if (root->right_ != NULL) {
      height_R = computeHeight(root->right_);
    }
    return (std::max(height_L, height_R) + 1);
  }
}

bool isHeightBalanced(TreeNode* root) {
  int height_R = -1;
  int height_L = -1;

  if (root == nullptr) {
    return true;
  } else {
    height_R = computeHeight(root->right_);
    height_L = computeHeight(root->left_);
    int balance_factor = height_R - height_L;
    if (balance_factor <= 1 && balance_factor >= -1) {
      return true;
    } else {
      return false; 
    }
  }
}