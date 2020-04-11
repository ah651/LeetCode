#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
#include <random>

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) return 0; 
        vector<int> tmp(nums.size()+2, 1); 
        for (int i = 0; i < nums.size(); i++) {
            tmp[i+1] = nums[i];
        }
        vector<vector<int>> dp(tmp.size(), vector<int>(tmp.size(), -1));
        return dfs(tmp, 0, tmp.size()-1, dp);
    }
    int dfs(vector<int> & nums, int lo, int hi, vector<vector<int>> & dp) {
        if (lo+1 == hi) return 0;
        if (dp[lo][hi] != -1) return dp[lo][hi];

        int result = 0; 

        for (int i = lo+1; i < hi; i++) {
            int tmp = nums[lo]*nums[i]*nums[hi];
            tmp += dfs(nums, lo, i, dp);
            tmp += dfs(nums, i, hi, dp);
            if (tmp > result) result = tmp;
        }
        dp[lo][hi] = result;
        return result;
    }
};