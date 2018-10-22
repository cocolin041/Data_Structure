/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node* x = t->right;

    if (x->left != NULL) {
      t->right = x->left;
    } else {
      t->right = NULL;
    }

    x->left = t;
    t = x;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node* x = t->left;

    if (x->right != NULL) {
      t->left = x->right;
    } else {
      t->left = NULL;
    }

    x->right = t;
    t = x;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    int factor_L = -1;
    int factor_R = -1;

    Node* curr = subtree;
    
    if (subtree != NULL) {
      if (subtree->left != NULL) {
        factor_L = ComputeBalanceFactor(subtree->left);
        subtree->left->height = computeHeight(subtree->left);
      }
      if (subtree->right != NULL) {
        factor_R = ComputeBalanceFactor(subtree->right);
        subtree->right->height = computeHeight(subtree->right);
      }
      // rotate right for the final step
      if (ComputeBalanceFactor(subtree) == 2) {
        if (factor_R == 1) {
          rotateLeft(subtree);
          
        }
        if (factor_R == -1) {
          rotateRightLeft(subtree);
        }
      }
      // rotate left for the final step
      if (ComputeBalanceFactor(subtree) == -2) {
        if (factor_L == -1) {
          rotateRight(subtree);
        }
        if (factor_L == 1) {
          rotateLeftRight(subtree);
        }
      }
      subtree->height = computeHeight(subtree);
    }
    if (subtree->left != NULL) {
      rebalance(subtree->left);
    }
    if (subtree->right != NULL) {
      rebalance(subtree->right);
    }
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    Node *nodeInsert = new Node(key, value);

    if (subtree != NULL) {
      Node *curr = subtree;
      while (curr != NULL) {

        if (key < curr->key) {
          if (curr->left != NULL) {
            curr = curr->left;
          } else {
            curr->left = nodeInsert;
            curr = NULL;
          }
        } else {
          if (curr->right != NULL) {
            curr = curr->right;
          } else {
            curr->right = nodeInsert;
            curr = NULL;
          }
        } 
      }
      rebalance(subtree);
      
    } else {
      subtree = nodeInsert;
    }
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    Node* old_root = subtree;
    if (subtree == NULL)
        return;
    
    K subtree_key = subtree->key;
    if (key < subtree->key) {
        // your code here
        if (subtree->left != NULL) {
          remove(subtree->left, key);
        }
    } else if (key > subtree->key) {
        // your code here
        if (subtree->right != NULL) {
          remove(subtree->right, key);
        }
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            subtree = NULL;
            rebalance(root);
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node* curr = subtree;
            if (curr->left != NULL) {
              curr = curr->left;
            }
            while (curr->right != NULL) {
              curr = curr->right;
            }
            swap(subtree, curr);

            curr = subtree;

            if (curr->left != NULL) {
              curr = curr->left;
            }
            while (curr->right != NULL && curr->right->key != subtree_key) {
              curr = curr->right;
            }
            curr->right = NULL;
            
            rebalance(root);

        } else {
            /* one-child remove */
            // your code here
            //child on left
            if (subtree->left != NULL) {
              Node* temp = subtree;
              subtree = subtree->left;
              delete temp;
              temp = NULL;
              rebalance(root);
            }
            //child on right
            if (subtree->right != NULL) {
              Node* temp = subtree;
              subtree = subtree->right;
              delete temp;
              temp = NULL;
              rebalance(root);
            }
        }
    }
}
template <class K, class V>
int AVLTree<K, V>::ComputeBalanceFactor(Node* t) {
  int height_L = -1;
  int height_R = -1;
  if (t->left != NULL) {
    height_L = computeHeight(t->left);
  }
  if (t->right != NULL) {
    height_R = computeHeight(t->right);
  }
  return (height_R - height_L);
}

template <class K, class V>
int AVLTree<K, V>::computeHeight(Node* t) {
  int height = -1;
  int height_L = -1;
  int height_R = -1;

  if (t == NULL) {
    return -1;
  } else {
    if (t->left == NULL && t->right == NULL) {
      return 0;
    } else if (t->left != NULL && t->right != NULL) {
      height_R = computeHeight(t->right);
      height_L = computeHeight(t->left);
      
    } else if (t->left == NULL && t->right != NULL) {
      height_L = -1;
      height_R = computeHeight(t->right);
    } else if (t->left != NULL && t->right == NULL) {
      height_R = -1;
      height_L = computeHeight(t->left);
    }
    if (height_L >= height_R) {
      return (height_L + 1);
    } else {
      return (height_R + 1);
    }
  }
}