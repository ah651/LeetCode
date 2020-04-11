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
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(2, vector<int>(N+1, 0)); 
        for (int i = 0; i <= N; i++) {
            dp[1][i] = i;
        }
        dp[0][1] = 1;
        
        for (int i = 2; i <= K; i++) {
            for (int j = 2; j <= N; j++) {
                int lo = 1, hi = j; int res = INT_MAX; 
                while(lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (dp[(i-1)%2][mid-1] > dp[i%2][j-mid]) {
                        res = min(res, dp[(i-1)%2][mid-1]);
                        hi = mid-1;
                    } else {
                        res = min(res, dp[i%2][j-mid]);
                        lo = mid+1;
                    }
                }
                dp[i%2][j] = 1+res;
            }
        }
        return dp[K%2][N];
    }
};