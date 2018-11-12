#include <iostream>
using namespace std;

vector<string> NoProblem(int start, vector<int> created, vector<int> needed) {

    // your code here
    vector<string> problem;
    unsigned size = created.size();
    vector<int> acc_created(size);
    acc_created[0] = start;
    // for (unsigned i = 1; i < created.size(); i++) {
    //     acc_created[i] = acc_created[i - 1] + created[i - 1];
    // }
    for (unsigned i = 0; i < needed.size(); i++) {
        if ((int)i > 0) {
            acc_created[i] = acc_created[i - 1] + created[i - 1];
        }
        if (needed[i] <= acc_created[i]) {
            problem.push_back("No problem! :D");
            acc_created[i] = acc_created[i] - needed[i];
        } else {
            problem.push_back("No problem. :(");
        }
    }
    return problem;
}
