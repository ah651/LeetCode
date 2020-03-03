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
    int mySqrt(int x) {
        if (x == 0) return 0;
        //newton method
        double cur = 1, pre = x;
        while (fabs(cur-pre) > 1e-9) {
            pre = cur;
            cur = 1.0/2 * (pre + x/pre);
        }
        return int(cur);
    }
};