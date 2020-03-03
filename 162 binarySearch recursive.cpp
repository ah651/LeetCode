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
        return binarySearch(nums, 0, nums.size()-1);
    }
    int binarySearch(vector<int> & nums, int lo, int hi) {
        if (lo == hi) return lo; 
        int mid = (lo + hi) / 2;
        if (nums[mid] > nums[mid+1]) {
            return binarySearch(nums, lo, mid);
        } else {
            return binarySearch(nums, mid+1, hi);
        }
    }
};