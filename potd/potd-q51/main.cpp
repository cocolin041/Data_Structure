#include "potd.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
	// test your code here!
	vector<string> result = topThree("in1.txt");
	vector<string> answer;

	answer.push_back("66");
	answer.push_back("44");
	answer.push_back("73");

	std::cout << (result == answer) << std::endl;

	return 0;
}
