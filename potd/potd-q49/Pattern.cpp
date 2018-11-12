#include "Pattern.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>

bool wordPattern(std::string pattern, std::string str) {

    //write your code here
    vector<string> words;
    string word;
    for (char t : str) {		
        if (t == ' ' && word.length() > 1) {
            words.push_back(word);
            word = "";
        } else if (t != ' ') {
            word += t;
        }
    }
    if (word != "") {
        words.push_back(word);
    }

    std::map<char, string> pattern_str;
    std::map<string, char> str_pattern;
    
    for (unsigned i = 0; i < pattern.length(); i++) {
        bool v1 = (pattern_str[pattern[i]] == "");
        bool v2 = (str_pattern[words[i]] == char(0));

        bool v3 = pattern_str[pattern[i]] != words[i];
        // bool v4 = str_pattern[words[i]] != pattern[i];
        if (v1 && v2) {
            pattern_str[pattern[i]] = words[i];
            str_pattern[words[i]] = pattern[i];
            // std::cout << pattern[i] << " correspond to " << pattern_str[pattern[i]] << std::endl;
            // std::cout << words[i] << " correspond to " << str_pattern[words[i]] << std::endl;
        } else if (v3) {
            // std::cout << pattern[i] << " with string " << words[i] << std::endl;
            // std::cout << words[i] << " with pattern " << str_pattern[words[i]] << std::endl;
            return false;
        }
    }
    return true;
}

