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

struct Pos {
    int i;
    int j;
    Pos(int a = 0, int b = 0) : i(a), j(b) {};
    bool operator< (const Pos & b) const {
        if (i < b.i) {
            return true;
        } else if (i > b.i) {
            return false;
        } else {
            return j < b.j;
        }
    }
};

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (*matrix == '\0' || rows == 0 || cols == 0) {
            return false;
        }
        if (*str == '\0') {
            return true;
        }
        length = 0;
        cnt.clear();
        while (*str) {
            cnt[*str]++;
            length++;
            str++;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (cnt.find(matrix[i*cols+j]) != cnt.end()) {
                    map<char, int> word = cnt;
                    path.clear();
                    bool b = dfs(matrix, rows, cols, Pos(i, j), word, 0);
                    if (b) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool dfs(char * matrix, int rows, int cols, Pos p, map<char, int> & words, int checked) {
        if (words.count(matrix[p.i*cols + p.j]) == 0 || words[matrix[p.i*cols + p.j]] == 0 || path.find(p) != path.end()) {
            return false;
        }
        words[matrix[p.i*cols + p.j]]--;
        checked++;
        path.insert(p);
        if (length == checked) {
            return true;
        }
        //left
        if (p.j -1 >= 0) {
            if(dfs(matrix, rows, cols, Pos(p.i, p.j-1), words, checked)) return true;
        }
        //right
        if (p.j +1 < cols) {
            if(dfs(matrix, rows, cols, Pos(p.i, p.j+1), words, checked)) return true;
        }
        //up
        if (p.i -1 >= 0) {
            if(dfs(matrix, rows, cols, Pos(p.i-1, p.j), words, checked)) return true;
        }
        //down
        if (p.i +1 < rows) {
            if(dfs(matrix, rows, cols, Pos(p.i+1, p.j), words, checked)) return true;
        }

        words[matrix[p.i*cols + p.j]]++;
        checked--;
        path.erase(p);
        return false;
    }
    map<char, int> cnt;
    set<Pos> path;
    int length = 0;
};