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
    int max(int a, int b) {
        return a >= b? a : b;
    }
    int abs(int i) {
        return i >= 0? i : -i;
    }
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        if (k >= prices.size()) {
            k = prices.size()-1;
        }
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(k+1, vector<int>(2, 0)));

        for (int i = 0; i <= k; i++) {
            dp[0][i][1] = INT_MIN;
        }
        for (int i = 0; i <= prices.size(); i++) {
            dp[i%2][0][1] = INT_MIN;
        }
        for (int i = 1; i < prices.size()+1; i++) {
            for (int j = 1; j < k+1; j++) {
                dp[i%2][j][0] = max(dp[abs(i%2-1)][j][0], dp[abs(i%2-1)][j][1]+prices[i-1]);
                dp[i%2][j][1] = max(dp[abs(i%2-1)][j][1], dp[abs(i%2-1)][j-1][0]-prices[i-1]);
            }
        }


        return dp[prices.size()%2][k][0];
    }
};

