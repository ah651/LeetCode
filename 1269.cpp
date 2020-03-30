#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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
#include <functional> 
using namespace std;
#include <random>

class Solution {
public:
    int numWays(int steps, int arrLen) {
        if (steps <= 0 || arrLen <= 0) return -1; 
        arrLen = min(arrLen, (steps)+1); 
        vector<vector<unsigned long long>> dp(2, vector<unsigned long long>(arrLen, 0));
        vector<int> dx = {1, -1, 0};
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j < min(steps-i+1, arrLen); j++) {
                dp[i%2][j] = 0;
                for (int k = 0; k < dx.size(); k++) {
                    if (0 <= j+dx[k] && j+dx[k] < arrLen) {
                            dp[i%2][j] += dp[(i+1)%2][j+dx[k]];
                            dp[i%2][j] %= int(1e9+7);
                    }
                }
            }
        }
        return dp[(steps)%2][0];

    }
};