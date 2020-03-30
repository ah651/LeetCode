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
    int maxDistance(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return -1;
        } 
        bool has_water = false; 
        queue<pair<int, int>> q;
        int row = grid.size(), col = grid[0].size(); 
        vector<vector<int>> dis(row, vector<int>(col, INT_MAX));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) {
                    q.push(make_pair(i, j));
                    dis[i][j] = 0;
                } else {
                    has_water = true;
                }
            }
        }
        if (!has_water || q.empty()) return -1;
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0}; 
        pair<int, int> tmp;
        while (!q.empty()) {
            tmp = q.front(); q.pop(); 
            for (int i = 0; i < 4; i++) {
                int a = tmp.first + dx[i];
                int b = tmp.second + dy[i];
                if (a < 0 || b < 0 || a >= row || b >= col) continue;
                if (dis[a][b] == INT_MAX) {
                    dis[a][b] = dis[tmp.first][tmp.second] + 1;
                    q.push(make_pair(a, b));
                }
            }
        }
        return dis[tmp.first][tmp.second];
    }
};