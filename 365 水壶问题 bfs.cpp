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

struct Hash_pair {
    size_t operator() (const pair<int, int> & p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    int x = 0, y = 0;
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false; 
        if (z < 0) return false; 
        this->x = x;  
        this->y = y; 
        //use bfs, state space search
        queue<pair<int, int>> q; 
        unordered_set<pair<int, int>, Hash_pair> visited;
        q.push(make_pair(0, 0));
        visited.insert(make_pair(0, 0));
        while (!q.empty()) {
            auto state = q.front(); q.pop(); 
            //traverse 6 next state 
            // empty
            auto nexts = next_state(state); 
            for (auto n : nexts) {
                if (n.first + n.second == z) return true; 
                if (n.first <= x && n.second <= y && visited.find(n) == visited.end()) {
                    q.push(n);
                    visited.insert(n);
                } 

            }

        }
        return false; 
    }
    vector<pair<int, int>> next_state(const pair<int, int> & s) {
        vector<pair<int, int>> result; 
        result.push_back(make_pair(0, s.second));
        result.push_back(make_pair(s.first, 0));
        result.push_back(make_pair(x, s.second));
        result.push_back(make_pair(s.first, y));
        int remain = min(x - s.first, s.second); 
        result.push_back(make_pair(s.first+remain, s.second-remain)); 
        remain = min(y - s.second, s.first); 
        result.push_back(make_pair(s.first-remain, s.second+remain));
        return result; 
    }
    
};