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
    int movingCount(int m, int n, int k) {
        if (m <= 0 || n <= 0) return 0;
        if (k == 0) return 1; 
        result = 0;
        this->k = k;
        this->m = m;
        this->n = n;
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        dfs(visited, 0,0);
        return result;
    }
    int result = 0;
    int k = 0;
    int m = 0; 
    int n = 0;
    int dfs(vector<vector<bool>>& visited, int a, int b) {
        if (!check(a, b) || visited[a][b]) {
            return 0;
        } else {
            visited[a][b] = true;
            int r = dfs(visited, a+1, b);
            int d = dfs(visited, a, b+1);
            result++;
            return 1+r+d;
        }
    }
    bool check(int a, int b) {
        if (a < 0 || a >= m || b < 0 || b >= n) {
            return false;
        }
        int cnt = 0; 
        while (a) {
            cnt += a % 10;
            a /= 10;
        }
        while (b) {
            cnt += b % 10;
            b /= 10;
        }
        return cnt <= k;
    }
};