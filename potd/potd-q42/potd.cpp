#include <unordered_map>

using namespace std;

unordered_map<string, int> common_elems(unordered_map<string, int>& mapA,
                                        unordered_map<string, int>& mapB) {

    // your code here
    unordered_map<string, int> newMap({});
    unordered_map<string, int>::iterator it_A = mapA.begin();

    while (it_A != mapA.end()) {
        unordered_map<string, int>::iterator common;
        if (mapB.find(it_A->first) != mapA.end()) {
            common = mapB.find(it_A->first);
            newMap.insert({common->first, mapA.at(common->first) + mapB.at(common->first) });
            mapA.erase(it_A);
            mapB.erase(common);
            it_A = mapA.begin();
        } else {
            it_A++;
        }
    }
    // return unordered_map<string, int>();
    return newMap;
} 