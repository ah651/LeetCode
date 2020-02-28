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
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> piles; 
        for (int i = 0; i < nums.size(); i++) {
            int pos = binary_search(piles, nums[i]);
            if (pos >= piles.size()) {
                piles.push_back(nums[i]);
            } else {
                piles[pos] = nums[i];
            }
        }
        return piles.size();
    }
    int binary_search(vector<int> & piles, int target) {
        int lo = 0, hi = piles.size()-1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (piles[mid] == target) {
                return mid;
            } else if (piles[mid] < target) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return lo;
    }
};