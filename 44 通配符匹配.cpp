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
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[s.size()][p.size()] = true;
        for (int i = s.size(); i >= 0; i--) {
            for (int j = p.size()-1; j >= 0; j--) {
                if (p[j] == '*') {
                    if (i == s.size()) {
                        dp[i][j] = dp[i][j+1];
                    } else 
                        dp[i][j] = dp[i][j+1] || dp[i+1][j];
                } else {
                    bool match_cur = i < s.size() && ((s[i] == p[j]) || (p[j] == '?') || (p[j] == '*'));
                    dp[i][j] = match_cur && dp[i+1][j+1];
                }
            }
        }

        return dp[0][0];
    }
};