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
    int min(const int a, const int b) {
        return a <= b ? a : b;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), 0));
        if (dungeon[dungeon.size()-1][dungeon[0].size()-1] >= 0) {
            dp[dungeon.size()-1][dungeon[0].size()-1] = 1;    
        } else {
            dp[dungeon.size()-1][dungeon[0].size()-1] = 1-dungeon[dungeon.size()-1][dungeon[0].size()-1];
        }
        for (int i = dungeon.size()-1; i >= 0; i--) {
            for (int j = dungeon[0].size()-1; j >= 0; j--) {
                if (i != dungeon.size()-1 && j != dungeon[0].size()-1) {
                    if (dungeon[i][j] >= 0) {
                        dp[i][j] = min(dp[i+1][j] - dungeon[i][j] >= 1 ? dp[i+1][j] - dungeon[i][j] : 1, dp[i][j+1] - dungeon[i][j] >= 1 ? dp[i][j+1] - dungeon[i][j] : 1);
                    } else {
                        dp[i][j] = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j];
                    }
                } else if (i != dungeon.size()-1) {
                    if (dungeon[i][j] >= 0) {
                        dp[i][j] = dp[i+1][j] - dungeon[i][j] >= 1 ? dp[i+1][j] - dungeon[i][j] : 1;
                    } else {
                        dp[i][j] = dp[i+1][j] - dungeon[i][j];
                    }

                } else if (j != dungeon[0].size()-1) {
                    if (dungeon[i][j] >= 0) {
                        dp[i][j] = dp[i][j+1] - dungeon[i][j] >= 1 ? dp[i][j+1] - dungeon[i][j] : 1;
                    } else {
                        dp[i][j] = dp[i][j+1] - dungeon[i][j];
                    }

                }
            }
        }
        return dp[0][0];
    }
};
