#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Swiftcipher.h"

int main() {
    // call decipherer here!
  string message = decipherer("example.txt");
  std::cout << message << std::endl;
  
	return 0;	
}
