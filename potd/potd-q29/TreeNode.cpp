#include "TreeNode.h"
#include <iostream>

TreeNode * deleteNode(TreeNode* root, int key) {
  // your code here
  if (root == NULL) {
    return root;
  }
  if (key < root->val_) {
    root->left_ = deleteNode(root->left_, key);
  }
  else if (key > root->val_) {
    root->right_ = deleteNode(root->right_, key);
  }
  else {
    //node with no child or one child
    if (root->left_ == NULL) {
      TreeNode* temp = root->right_;
      delete root;
      root = NULL;
      return temp;
    }
    else if (root->right_ == NULL) {
      TreeNode* temp = root->left_;
      delete root;
      root = NULL;
      return temp;
    }
    //node with two child
    TreeNode* min = root;
    min = min->left_;
    while (min->right_ != NULL) {
      min = min->right_;
    }
    root->val_ = min->val_;
    root->left_ = deleteNode(root->left_, min->val_);
  }
  return root;
}

void inorderPrint(TreeNode* node)
{   
    
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
