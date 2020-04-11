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
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        check.clear();
        check = vector<vector<vector<int>>>(s1.size(), vector<vector<int>>(s2.size(), vector<int>(s1.size()+1, -1)));
        return dfs(s1, s2, 0, 0, s2.size(), check);
    }
    vector<vector<vector<int>>> check;
    bool dfs(string & s1, string & s2, int i, int j, int m, vector<vector<vector<int>>> & check) {
        if (m == 1) {
            if (s1[i] == s2[j]) return true;
            else return false;
        }
        if (check[i][j][m] != -1) {
            return check[i][j][m];
        }
        // k is len of left
        for (int k = 1; k < m; k++) {
            bool a = dfs(s1, s2, i, j, k, check);
            bool b = dfs(s1, s2, i+k, j+k, m-k, check);
            if (a && b) {
                check[i][j][m] = 1;
                return true;
            }

            bool c = dfs(s1, s2, i, j+m-k, k, check);
            bool d = dfs(s1, s2, i+k, j, m-k, check);
            if (c && d) {
                check[i][j][m] = 1;
                return true;
            }
        }
        check[i][j][m] = 0;
        return false;
    }
};