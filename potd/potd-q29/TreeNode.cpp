#include "TreeNode.h"
#include <iostream>

TreeNode * deleteNode(TreeNode* root, int key) {
  // your code here
  TreeNode *curr = root;

  if (root->val_ == key) {
    if (root->left_ == NULL && root->right_ == NULL) {
      //leaf node
      root = NULL;
    } else if (root->left_ == NULL && root->right_ != NULL) {
      //with one child on the right
      root = root->right_;
    } else if (root->left_ != NULL && root->right_ == NULL) {
      //with one child on the left
      root = root->left_;
    } else {
      curr = curr->left_;
      while (curr->right_->right_ != NULL) {
        curr = curr->right_;
      }
      TreeNode *& temp = curr->right_;
      curr->right_->right_ = root->right_;
      curr->right_->left_ = root->left_;
      root = curr->right_;
      temp = NULL;
    }
  } else {
    if (curr->left_ != NULL) {
      if (curr->left_->val_ == key) {
        TreeNode *&want = curr->left_;
        if (want->left_ == NULL && want->right_ == NULL) {
          //leaf node
          want = NULL;
        } else if (want->left_ == NULL && want->right_ != NULL) {
          //with one child on the right
          curr->left_ = want->right_;
        } else if (want->left_ != NULL && want->right_ == NULL) {
          //with one child on the left
          curr->left_ = want->left_;
        } else {
          //with two children
          TreeNode *& temp = want->left_;
          TreeNode *& temp2 = curr;
          curr = curr->right_;
          while (curr->left_->left_ != NULL) {
            curr = curr->left_;
          }
          curr->left_ = temp2;
          curr->left_ = NULL;
        }
      } else {
        deleteNode(curr->left_, key);
      }
    }
    if (curr->right_ != NULL) {
      if (curr->right_->val_ == key) {
        TreeNode *&want = curr->right_;
        if (want->left_ == NULL && want->right_ == NULL) {
          //leaf node
          want = NULL;
        } else if (want->left_ == NULL && want->right_ != NULL) {
          //with one child on the right
          curr->right_ = want->right_;
        } else if (want->left_ != NULL && want->right_ == NULL) {
          //with one child on the left
          curr->right_ = want->left_;
        } else {
          //with two children
          TreeNode *& temp = want->left_;
          want = want->right_;
          want->left_ = temp;
        }
      } else {
        deleteNode(curr->right_, key);
      }
    }
    curr = root;
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
