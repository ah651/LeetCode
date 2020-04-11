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
        for(int i = 0; i < nums.size(); i++) {
            tmp[i+1] = nums[i];
        }
        vector<vector<int>> dp(tmp.size(), vector<int>(tmp.size(), 0));
        for (int i = tmp.size()-1; i >= 0; i--) {
            for (int j = i+2; j < tmp.size(); j++) {
                int result = 0; 
                for (int k = i+1; k < j; k++) {
                    int t = tmp[i]*tmp[k]*tmp[j];
                    t += dp[i][k];
                    t += dp[k][j];
                    if (t > result) result = t;
                }
                dp[i][j] = result;
            }
        }
        return dp[0][tmp.size()-1];
    }
};