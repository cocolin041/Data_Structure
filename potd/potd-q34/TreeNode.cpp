#include "TreeNode.h"

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
	// Your code here
  int height_L = -1;
  int height_R = -1;
  int factor = 0;
  int height_child_L = -1;
  int height_child_R = -1;
  int factor_child = 0;

  if (leftHeavy(subroot) == true) {
    if (subroot->left_ != NULL) {
      height_L = getHeight(subroot->left_);
      if (subroot->left_->left_ != NULL) {
        height_child_L = getHeight(subroot->left_->left_);
      }
      if (subroot->left_->right_ != NULL) {
        height_child_R = getHeight(subroot->left_->right_);
      }
    }
    if (subroot->right_ != NULL) {
      height_R = getHeight(subroot->right_);
    }
    factor = height_R - height_L;
    factor_child = height_child_R - height_child_L;
  } else {
    if (subroot->left_ != NULL) {
      height_L = getHeight(subroot->left_);
    }
    if (subroot->right_ != NULL) {
      height_R = getHeight(subroot->right_);
      if (subroot->right_->left_ != NULL) {
        height_child_L = getHeight(subroot->right_->left_);
      }
      if (subroot->right_->right_ != NULL) {
        height_child_R = getHeight(subroot->right_->right_);
      }
    }
    factor = height_R - height_L;
    factor_child = height_child_R - height_child_L;
  }
  if (factor == 2) {
    if (factor_child == 1) {
      return TreeNode::left;
    }
    if (factor_child == -1) {
      return TreeNode::rightLeft;
    }
  }
  if (factor == -2) {
    if (factor_child == 1) {
      return TreeNode::leftRight;
    }
    if (factor_child == -1) {
      return TreeNode::right;
    }
  }

  return TreeNode::right;
}
