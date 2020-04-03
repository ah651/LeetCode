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
    int make(int n) {
        if ((n>>7 & 1) == 0) return 0; 
        if ((n>>6 & 3) == 2) return 1;
        if ((n>>5 & 7) == 6) return 2;
        if ((n>>4 & 15) == 14) return 3;
        if ((n>>3 & 31) == 30) return 4;
        return -1;
    }
    bool validUtf8(vector<int>& data) {
        vector<vector<int>> transfer = {{0, -1, 1, 2, 3}, {-1, 0, -1, -1, -1}, {-1, 1, -1, -1, -1}, {-1, 2, -1, -1, -1}};
        int state = 0; 
        for (int i = 0; i < data.size(); i++) {
            int tmp = make(data[i]); 
            if (tmp == -1) return false; 
            state = transfer[state][tmp]; 
            if (state == -1) return false;
        }
        if (state == 0) return true; 
        else return false;
    }
};