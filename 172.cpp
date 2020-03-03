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
    int trailingZeroes(int n) {
        // count how many 2*10 in range(1,n+1)
        int cnt = 0;
        while (n) {
            cnt += n / 5;
            n /= 5;
        }
        return cnt;
    }
};