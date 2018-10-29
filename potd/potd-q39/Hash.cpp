#include <vector>
#include <string>
#include "Hash.h"

using namespace std;

int hashFunction(string s, int M) {
   // Your Code Here
   //hash function to sum up the ASCII characters of the letters of the string
	 int sum = 0;
	 for (unsigned i = 0; i < s.length(); i++) {
		 sum += int(s[i]);
	 }
	 return (sum % M);
 }

int countCollisions (int M, vector<string> inputs) {
	int collisions = 0;
	vector<string> table(M);

	// Your Code Here
	for (unsigned i = 0; i < inputs.size(); i++) {
		int result = hashFunction(inputs[i], M);
		if (table[result].size() != 0) {
			collisions += 1;
		} else {
			table[result] = inputs[i];
		}
	}
	return collisions;
}
