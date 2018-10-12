#include "potd.h"
#include <iostream>
using namespace std;

int main() {
  // Test 1: An empty list
  Node * head = NULL;
  cout << stringList(head) << endl;

  // Test 2: A list with exactly one node
  Node * head2 = new Node();
  head2->data_ = 100;
  cout << stringList(head2) << endl;

  // Test 3: A list with more than one node
  Node * head3 = new Node();
  head3->data_ = 100;
  Node * head4 = new Node();
  head3->next_ = head4;
  head4->data_ = 200;
  Node * head5 = new Node();
  head4->next_ = head5;
  head5->data_ = 300;
  

  cout << stringList(head3) << endl;

  return 0;
}
