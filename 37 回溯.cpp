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
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>> & board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    char cnt = '1';
                    while (cnt <= '9') {
                        if(check(board, i, j, cnt)) {
                            board[i][j] = cnt;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                        cnt++;
                    }
                    return false;
                }
            }
        }
        return true; 
    }
    bool check(vector<vector<char>> & board, int row, int col, char cnt) {
        //row 
        for (int k = 0; k < 9; k++) {
            if (board[row][k] == cnt) return false;
        }
        //col 
        for (int k = 0; k < 9; k++) {
            if (board[k][col] == cnt) return false;
        }
        //square
        for (int k = 0; k < 9; k++) {
            if (board[row-row%3+k/3][col-col%3+k%3] == cnt) return false;
        }
        return true;
    }
};