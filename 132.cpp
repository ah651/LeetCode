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
    int minCut(string s) {
        if (s.size() <= 1) return 0; 
        vector<vector<int>> dp(s.size(), vector<int>(s.size())); 
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }
        for (int i = s.size()-1; i >= 0; i--) {
            for (int j = i+1; j < s.size(); j++) {
                if (s[i] == s[j] && (i+1 == j || dp[i+1][j-1])) {
                    dp[i][j] = 1; 
                }
            }
        }
        vector<int> myCut(s.size(), 0);
        for (int i = s.size()-2; i >= 0; i--) {
            if (dp[i][s.size()-1]) myCut[i] = 0; 
            else {
                int tmp = INT_MAX;
                for (int j = i; j < s.size(); j++) {
                    if (dp[i][j]) {
                        tmp = 1+myCut[j+1] < tmp ? 1+myCut[j+1] : tmp; 
                    }
                }
                myCut[i] = tmp; 
            }
        }
        return myCut[0];

    }
};