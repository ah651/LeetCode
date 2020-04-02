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
    int n = 0;
    vector<int> check_col; 
    vector<int> check_main; 
    vector<int> check_second;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result; 
        if (n == 0) return result;
        this->n = n; 
        check_col = vector<int>(n, 0); 
        check_main = vector<int>(2*n, 0); 
        check_second = vector<int>(2*n, 0);
        vector<string> path(n, string(n, '.')); 
        dfs(result, path, 0);
        return result;
    }
    void dfs(vector<vector<string>> & result, vector<string> path, int pos) {
        if (pos == n) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (check(pos, i)) {
                check_col[i] = 1; 
                if (i-pos >= 0) check_main[i-pos] = 1;
                else check_main[i-pos+check_main.size()] = 1; 
                check_second[pos+i] = 1;
                path[pos][i] = 'Q';
                dfs(result, path, pos+1);
                path[pos][i] = '.';
                check_col[i] = 0; 
                if (i-pos >= 0) check_main[i-pos] = 0;
                else check_main[i-pos+check_main.size()] = 0; 
                check_second[pos+i] = 0;

            }
        } 
    }
    bool check(int a, int b) {
        // row : a, col : b 
        if (check_col[b]) return false; 
        if (b-a >= 0) {
            if (check_main[b-a]) return false;
        } else {
            if (check_main[b-a+check_main.size()]) return false;
        }
        if (check_second[a+b]) return false; 
        return true;
    }
    bool check_chess(vector<string> & path) {
        for (int i = 0; i < n; i++) {
            int pos = -1; 
            for (int j = 0; j < n; j++) {
                if (path[i][j] == 'Q') {
                    pos = j; break;
                }
            }
            // col 
            for (int j = 0; j < n; j++) {
                if (j != i && path[j][pos] == 'Q') return false;
            }
            // main diag
            for (int j = 0; j < n; j++) {
                int b = pos + (j - i);
                if (j != i && b >= 0 && b < n && path[j][b] == 'Q') return false;
            }
            // diag diag
            for (int j = 0; j < n; j++) {
                int b = pos + (i - j);
                if (j != i && b >= 0 && b < n && path[j][b] == 'Q') return false;
            }
        }
        return true;
    }
};