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
    int palindromePartition(string s, int k) {
        if (s.size() <= k) return 0; 
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }      
        for (int i = s.size()-1; i >= 0; i--) {
            for (int j = i+1; j < s.size(); j++) {
                if (s[i] == s[j] && (i+1 == j || dp[i+1][j-1] == 1)) {
                    dp[i][j] = 1;
                }
            }
        }
        // start from i, cut as j segments, cost is k
        map<pair<int, int>, int> cut;
        return dfs(s, dp, cut, 0, k);
    }
    int dfs(string & s, vector<vector<int>> & dp, map<pair<int, int>, int> & cut, int pos, int k) {
        if (s.size()-pos < k) return INT_MAX; 
        auto p = make_pair(pos, k); 
        if (cut.find(p) != cut.end()) return cut[p]; 
        if (s.size()-pos == k) {
            cut[p] = 0; 
            return 0;
        }
        if (k == 1) {
            if (dp[pos][s.size()-1]) return 0; 
            int c = cost(s, pos, s.size()-1);
            cut[p] = c; 
            return c;
        }
        int tmp = INT_MAX; 
        for (int i = pos+1; i < s.size(); i++) {
            int r = dfs(s, dp, cut, i, k-1); 
            if (r != INT_MAX) {
                int l = dp[pos][i-1] ? 0 : cost(s, pos, i-1);
                if (l + r < tmp) {
                    tmp = l + r;
                }
            }
        }
        cut[p] = tmp; 
        return tmp;

    }
    int cost(string & s, int pos, int pos2) {
        int i = pos, j = pos2; 
        int cnt = 0;
        while (i < j) {
            if (s[i] != s[j]) cnt++;
            i++; j--;
        }
        return cnt;
    }
};