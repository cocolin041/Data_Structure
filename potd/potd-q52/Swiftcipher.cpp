#include "Swiftcipher.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/* Swift Cipher: Frequency of words in a file corresponds to its location in the decrypted sentence */
string decipherer(string filename) {
	map<string, int> frequency;
	string line;
	ifstream infile (filename);
	string message;
	vector<int> freq;

	if (infile.is_open()) {
			while (getline(infile, line)) {
					map<string, int>::iterator it = frequency.find(line);
					if (it == frequency.end()) {
							frequency.insert({line, 1});
					} else {
							it->second += 1;
					}
			}
	}
	infile.close();

	for (auto iterator = frequency.begin(); iterator != frequency.end(); ++iterator) {
			freq.push_back(iterator->second);
	}
	sort(freq.begin(), freq.end());

	for (unsigned i = 0; i < freq.size(); i++) {
			for (map<string, int>::iterator it = frequency.begin(); it != frequency.end(); ++it) {
					if (it->second == freq[i]) {
						message += it->first;
						if (i != freq.size() - 1) {
							message += " ";
						}
						break;
					}
			}
	}

	return message;
}
