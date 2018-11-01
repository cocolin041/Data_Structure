#include <iostream>
#include "potd.cpp"

using namespace std;

int main() {
    unordered_map<string, int> mapA({
                                    {"d", 13},
                                    {"e", 17},
                                    {"f", 17}
                                    });
    unordered_map<string, int> mapB({
                                    {"common", 17},
                                    {"a", 17},
                                    {"b", 17},
                                    {"c", 17}
                                    });
    unordered_map<string, int> common = common_elems(mapA, mapB);

    // check your outputs here
    std::cout << "newMap" << std::endl;
    for (unordered_map<string, int>::iterator it = common.begin(); it!=common.end(); it++) {
        std::cout << "1st: " << it->first << "| 2nd: " << it->second << std::endl;
    }
    std::cout << "mapA" << std::endl;
    for (unordered_map<string, int>::iterator it = mapA.begin(); it!=mapA.end(); it++) {
        std::cout << "1st: " << it->first << "| 2nd: " << it->second << std::endl;
    }
    std::cout << "mapB" << std::endl;
    for (unordered_map<string, int>::iterator it = mapB.begin(); it!=mapB.end(); ++it) {
        std::cout << "1st: " << it->first << "| 2nd: " << it->second << std::endl;
    }
}
