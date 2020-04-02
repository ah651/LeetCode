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
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return; 
        int row = board.size(), col = board[0].size();
        this->row = row; this->col = col;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int tmp = live_cnt(board, i, j);
                if (board[i][j]) {
                    if (tmp == 2 || tmp == 3) board[i][j] |= 2; 
                } else {
                    if (tmp == 3) board[i][j] |= 2;
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                board[i][j] >>= 1;
            }
        }
    }
    int row = 0;
    int col = 0;
    vector<int> dx = {0, -1, -1, -1, 0, 1, 1, 1};
    vector<int> dy = {-1, -1, 0, 1, 1, 1, 0, -1};
    int live_cnt(vector<vector<int>> & board, int a, int b) {
        int cnt = 0; 
        for (int i = 0; i < dx.size(); i++) {
            if (a+dx[i] >= 0 && a+dx[i] < row && b+dy[i] >= 0 && b+dy[i] < col) {
                if (board[a+dx[i]][b+dy[i]] & 1) {
                    cnt++;
                }
            }
        }
        return cnt;

    }
};