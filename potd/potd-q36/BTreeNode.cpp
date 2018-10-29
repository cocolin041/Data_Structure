#include <vector>
#include "BTreeNode.h"
#include <iostream>

std::vector<int> traverse(BTreeNode* root) {
    // your code here
    std::vector<int> v;
    unsigned i = 0;

    if (root == NULL) {
        return {};
    }

    if (root->is_leaf_ == true) {
        for (unsigned j = 0; j < root->elements_.size(); j++) {
            v.push_back(root->elements_[j]);
            // std::cout << root->elements_[j] << std::endl;
        }
        return v;
    } else {
        std::vector<int> u;
        while (i < root->elements_.size()) {
            u = traverse(root->children_[i]);
            u.push_back(root->elements_[i]);
            // std::cout << root->elements_[i] << std::endl;
            v.insert(v.end(), u.begin(), u.end());
            i++;
        }
        u = traverse(root->children_[i]);
        v.insert(v.end(), u.begin(), u.end());
    }
    return v;
}
