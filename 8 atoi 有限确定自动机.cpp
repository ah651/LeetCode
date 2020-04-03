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
            case ' ': return 0; 
            case '+':
            case '-': return 1;
            default:
                if (c >= '0' && c <= '9') return 2;
                else return -1;
        }
    }
    int myAtoi(string str) {
        vector<vector<int>> transfer = {{0, 1, 2}, {-1, -1, 2}, {-1, -1, 2}};
        int state = 0;
        int sign = 1;
        long long result = 0; 
        for (int i = 0; i < str.size(); i++) {
            int col = make(str[i]); 
            if (col == -1) return sign*result; 
            state = transfer[state][col];
            if (state == -1) return sign*result;
            if (state == 1 && str[i] == '-') {
                sign = -1;
            }
            if (state == 2) {
                result *= 10; result += str[i] - '0'; 
                if (sign == 1 && sign*result >= INT_MAX) return INT_MAX;
                if (sign == -1 && sign*result <= INT_MIN) return INT_MIN;
            }
        }
        return sign*result;

    }
};