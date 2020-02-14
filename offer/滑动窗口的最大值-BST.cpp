#include <vector> 
#include <list>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
#include <climits>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

#include <random>


class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        //BST version (set/map);
        vector<int> result;
        multiset<int> ms;
        if (num.size() < size || size == 0) {
            return result;
        }
        for (int i = 0; i < size-1; i++) {
            ms.insert(num[i]);
        }
        for (int i = size-1; i < num.size(); i++) {
            if (i > size-1) {
                ms.erase(num[i-size]);
            }
            ms.insert(num[i]);
            result.push_back(*ms.rbegin());
        }
        return result;
    }
};