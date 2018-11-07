#include "MinHeap.h"
#include <math.h>
using namespace std;

vector<int> lastLevel(MinHeap & heap)
{
        // Your code here
        int num = heap.elements.size() - 1;
        int h = log2(num);

        vector<int> last;

        for (int i = pow(2, h); i <= num; i++) {
                last.push_back(heap.elements[i]);
        }
        return last;
}

