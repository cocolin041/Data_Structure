#include "TreeNode.h"
#include <iostream>

TreeNode* findLastUnbalanced(TreeNode* root) {
  TreeNode *left_unbalance = nullptr;
  TreeNode *right_unbalance = nullptr;

  if (root != NULL) {
    TreeNode *unbalance = root;
    if (isHeightBalanced(root) == false) {
      if (root->left_ == NULL && root->right_ == NULL) {
        return unbalance;
      } else {

        if (root->left_ != NULL) {
          left_unbalance = root->left_;
          if (isHeightBalanced(root->left_) == false) {
            left_unbalance = findLastUnbalanced(root->left_);
          } else {
            left_unbalance = root;
          }
        } else {
          left_unbalance = root;
        }

        if (root->right_ != NULL) {
            right_unbalance = root->right_;
          if (isHeightBalanced(root->right_) == false) {
            right_unbalance = findLastUnbalanced(root->right_);
          } else {
            right_unbalance = root;
          }
        } else {
          right_unbalance = root;
        }

        if (computeHeight(left_unbalance) >= computeHeight(right_unbalance)) {
          unbalance = left_unbalance;
        } else {
          unbalance = right_unbalance;
        }

      }
      
    } else {
      return NULL;
    }
  } else {
    return NULL;
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
bool isHeightBalanced(TreeNode* root) {
  int balance_factor = computeHeight(root->right_) - computeHeight(root->left_);
  if (balance_factor <= 1 && balance_factor >= -1) {
    return true;
  } else {
    return false; 
  }
}