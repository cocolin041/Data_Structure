#include "abstractsyntaxtree.h"

/**
 * Calculates the value from an AST (Abstract Syntax Tree). To parse numbers from strings, please use std::stod
 * @return A double representing the calculated value from the expression transformed into an AST
 */
double AbstractSyntaxTree::eval() const {
    // @TODO Your code goes here...

    return eval(root);
}

double AbstractSyntaxTree::eval(Node *subRoot) const {
    double result = 0;

    if (subRoot->left == NULL && subRoot->right == NULL) {
        return std::stod(subRoot->elem);
    }

    if (subRoot->elem == "+") {
        result = eval(subRoot->left) + eval(subRoot->right);
    }
    if (subRoot->elem == "/") {
        result = eval(subRoot->left) / eval(subRoot->right);    
    }
    if (subRoot->elem == "*") {
        result = eval(subRoot->left) * eval(subRoot->right);    
    }
    if (subRoot->elem == "-") {
        result = eval(subRoot->left) - eval(subRoot->right);    
    }

    return result;
}