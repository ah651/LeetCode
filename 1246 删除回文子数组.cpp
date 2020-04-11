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
    int delString(string s) {
        // 删除回文数组
        vector<vector<int>> cache(s.size(), vector<int>(s.size(), -1));
        return dfs(s, 0, s.size()-1, cache);
        
    }
    int dfs(string & s, int lo, int hi, vector<vector<int>> & dp) {
        if (lo > hi) return 0;
        if (lo == hi) return 1; 
        if (dp[lo][hi] != -1) return dp[lo][hi];
        int result = 1+dfs(s, lo+1, hi, dp);
        for (int i = lo+1; i <= hi; i++) {
            if (s[i] == s[lo]) {
                int tmp;
                if (i == lo+1) {
                    tmp = dfs(s, lo+2, hi, dp)+1;
                } else {
                    tmp = dfs(s, lo+1, i-1, dp) + dfs(s, i+1, hi, dp);
                }
                if (tmp < result) result = tmp;
            }
        }
        return result;
    }
};