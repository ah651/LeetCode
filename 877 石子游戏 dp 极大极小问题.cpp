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
    bool stoneGame(vector<int>& piles) {
        if (game(piles) > 0) return true;
        else return false;
    }
    int game(vector<int> & piles) {
        if (piles.size() == 1) return piles[0];

        vector<vector<pair<int, int>>> dp(piles.size(), vector<pair<int, int>>(piles.size(), make_pair(0, 0)));
        for (int i = 0; i < piles.size(); i++) {
            dp[i][i].first = piles[i];
            dp[i][i].second = 0;
        }        
        for (int l = 0; l < piles.size()-1; l++) {
            for (int i = 0; i < piles.size()-l-1; i++) {
                int j = i + l + 1;
                if (dp[i+1][j].second + piles[i] >= dp[i][j-1].second + piles[j]) {
                    dp[i][j].first = dp[i+1][j].second + piles[i];
                    dp[i][j].second = dp[i+1][j].first;
                } else {
                    dp[i][j].first = dp[i][j-1].second + piles[j];
                    dp[i][j].second = dp[i][j-1].first;
                }
            }
        }
        return dp[0][piles.size()-1].first - dp[0][piles.size()-1].second;
    }
};