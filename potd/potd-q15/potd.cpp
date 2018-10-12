#include "potd.h"
#include <iostream>
#include <string>

using namespace std;

string stringList(Node *head) {
    // your code here!
    if (head != NULL) {
        string result;
        int index = 0;
        result = "Node " + std::to_string(index) + ": " + std::to_string(head->data_);
        while (head->next_ != nullptr) {
            index += 1;
            head = head->next_;
            result += " -> Node " + std::to_string(index) + ": " + std::to_string(head->data_);
        }
        return result;
    } else {
        return "Empty list";
    }
}
