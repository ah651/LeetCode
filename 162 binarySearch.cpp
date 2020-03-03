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
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        int lo = 0, hi = nums.size()-1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > nums[mid+1]) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
};