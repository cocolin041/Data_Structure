#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


vector<string> topThree(string filename) {
    map<string, int> frequency;
    string line;
    ifstream infile (filename);
    vector<string> ret;
    vector<int> freq;

    if (infile.is_open()) {
        while (getline(infile, line)) {
            // do things
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
    reverse(freq.begin(), freq.end());

    for (unsigned i = 0; i < 3; i++) {
        for (map<string, int>::iterator it = frequency.begin(); it != frequency.end(); ++it) {
            if (it->second == freq[i]) {
                ret.push_back(it->first);
                break;
            }
        }
    }
    return ret;
}

