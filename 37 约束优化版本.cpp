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
        vector<vector<set<int> *>> sudoku(9, vector<set<int> *>(9, nullptr));
        queue<pair<int, int>> proposal;
        // init sudoku
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    sudoku[i][j] = new set<int>{1,2,3,4,5,6,7,8,9};
                } else {
                    sudoku[i][j] = nullptr; 
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int tmp = board[i][j] - '0';
                    //row 
                    for (int k = 0; k < 9; k++)    {
                        if (sudoku[i][k]) {
                            sudoku[i][k]->erase(tmp);
                            if (sudoku[i][k]->size() == 1) {
                                proposal.push(make_pair(i, k));
                            }
                        }
                    }
                    //col 
                    for (int k = 0; k < 9; k++) {
                        if (sudoku[k][j]) {
                            sudoku[k][j]->erase(tmp);
                            if (sudoku[k][j]->size() == 1) {
                                proposal.push(make_pair(k, j));
                            }
                        }
                    }
                    //square
                    for (int k = 0; k < 9; k++) {
                        if (sudoku[i-i%3+k/3][j-j%3+k%3]) {
                            sudoku[i-i%3+k/3][j-j%3+k%3]->erase(tmp);
                            if (sudoku[i-i%3+k/3][j-j%3+k%3]->size() == 1) {
                                proposal.push(make_pair(i-i%3+k/3, j-j%3+k%3));
                            }
                        }
                    }

                }
            }
        }
        while (!proposal.empty()) {
            pair<int, int> pos = proposal.front(); proposal.pop();
            if (board[pos.first][pos.second] == '.') {
                int tmp = *(sudoku[pos.first][pos.second]->begin());
                board[pos.first][pos.second] = char(tmp + '0');
                int i = pos.first; int j = pos.second;
                //row 
                for (int k = 0; k < 9; k++)    {
                    if (sudoku[i][k]) {
                        sudoku[i][k]->erase(tmp);
                        if (sudoku[i][k]->size() == 1) {
                            proposal.push(make_pair(i, k));
                        }
                    }
                }
                //col 
                for (int k = 0; k < 9; k++) {
                    if (sudoku[k][j]) {
                        sudoku[k][j]->erase(tmp);
                        if (sudoku[k][j]->size() == 1) {
                            proposal.push(make_pair(k, j));
                        }
                    }
                }
                //square
                for (int k = 0; k < 9; k++) {
                    if (sudoku[i-i%3+k/3][j-j%3+k%3]) {
                        sudoku[i-i%3+k/3][j-j%3+k%3]->erase(tmp);
                        if (sudoku[i-i%3+k/3][j-j%3+k%3]->size() == 1) {
                            proposal.push(make_pair(i-i%3+k/3, j-j%3+k%3));
                        }
                    }
                }
                sudoku[pos.first][pos.second] = nullptr;
            }
        }
    }
};