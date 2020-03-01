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
    int maximumGap(vector<int>& nums) {
        // radix sort
        if (nums.size() < 2) return 0;
        int exp = 1;
        int radix = 10;
        vector<int> nums_tmp(nums.size());
        int nums_max = 0;
        for (auto i : nums) {
            if (i > nums_max) nums_max = i;
        }
        while (nums_max / exp) {
            vector<int> cnt(radix, 0);
            // radix sort
            for (auto i : nums) {
                cnt[(i / exp) % radix]++;
            }
            for (int i = 1; i < radix; i++) {
                cnt[i] += cnt[i-1];
            }
            //sort nums
            for (int i = nums.size()-1; i >= 0; i--) {
                nums_tmp[cnt[(nums[i] / exp) % 10]-1] = nums[i];
                cnt[(nums[i] / exp) % 10]--;
            }
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = nums_tmp[i];
            }
            exp *= radix;
        }
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] > result) result = nums[i] - nums[i-1];
        }
        return result;
    }
};