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
        vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
        for (int i = 0; i <= N; i++) {
            dp[1][i] = i;
        }
        for (int i = 1; i <= K; i++) {
            dp[i][1] = 1;
        }
        if (N <= 1) return N;
        for (int j = 2; j <= N; j++) {
            for (int i = 2; i <= K; i++) {
                dp[i][j] = 1+dp[i-1][j-1]+dp[i][j-1];
                if (dp[i][j] >= N) {
                    return j;
                }
            }
        }
        return N;
    }
};