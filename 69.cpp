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
        //binary search 
        long long lo = 0, hi = x;
        while (lo < hi) {
            // it is important to take right mid
            long long mid = (lo + hi + 1) / 2;
            if (mid * mid > x) {
                hi = mid -1;
            } else {
                lo = mid;
            }
        }
        return lo;
    }
};