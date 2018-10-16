#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>
#include <map> 

using std::string;

map<char, string> char_codes; 

void storeCodes(string charString, HuffmanNode* huffmanTree) 
{ 
    if (huffmanTree == NULL) {
        return; 
    }
    if (huffmanTree->left_ == NULL && huffmanTree->right_ == NULL) {
        char_codes[huffmanTree->char_] = charString;
    }
    storeCodes(charString + "0", huffmanTree->left_); 
    storeCodes(charString + "1", huffmanTree->right_); 
} 

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */


string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    HuffmanNode* root = huffmanTree;
    string ss;
    int index = 0;
    
    while (index < (int)binaryString.length()) {
      if (huffmanTree->left_ == NULL && huffmanTree->right_ == NULL) {
        ss += huffmanTree->char_;
        huffmanTree = root;
      } else {
        if (binaryString[index] == '0') {
          index += 1;
          if (huffmanTree->left_ != NULL) {
              huffmanTree = huffmanTree->left_;
          }
        } else if (binaryString[index] == '1') {
          index += 1;
          if (huffmanTree->right_ != NULL) {
              huffmanTree = huffmanTree->right_;
          }
        }
      }
    }
    ss += huffmanTree->char_;
    return ss;
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */

string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string message;
    storeCodes("", huffmanTree);
    for (int i = 0; i < (int)charString.size(); i++) {
      message += char_codes[charString[i]];
    }
    return message;
}