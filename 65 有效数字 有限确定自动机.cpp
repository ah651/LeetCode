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
    int make(char c) {
        switch(c) {
            case 'e': return 1;
            case '+':
            case '-': return 2; 
            case '.': return 3; 
            case ' ': return 4; 
            default:
                if (c >= '0' && c <= '9') return 0;
                else return -1;
        }
    }
    bool isNumber(string s) {
        vector<vector<int>> transfer = {
            {1, -1, 2, 9, 0}, 
            {1, 3, -1, 4, 5}, 
            {1, -1, -1, 9, -1}, 
            {7, -1, 6, -1, -1}, 
            {8, 6, -1, -1, 5}, 
            {-1, -1, -1, -1, 5}, 
            {7, -1, 10, -1, -1}, 
            {7, -1, -1, -1, 5}, 
            {8, 6, -1, -1, 5},
            {8, -1, -1, -1, -1},
            {7, -1, -1, -1, -1}};
        int state = 0; 
        for (int i = 0; i < s.size(); i++) {
            int tmp = make(s[i]);
            if (tmp == -1) return false; 
            state = transfer[state][tmp];
            if (state == -1) return false;
        }
        int check = 0x1b2;
        if (1 << state & check) return true; 
        else return false;
    }
};