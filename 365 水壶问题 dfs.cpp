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
    size_t operator()(const pair<int, int> & p) const {
        return p.first % int(1e9+7) + p.second % int(1e9+9);
    }
};
struct Equal_pair {
    bool operator()(const pair<int, int> & a, const pair<int, int> & b) const {
        return a.first == b.first && a.second == b.second;
    }
};

class Solution {
public:
    int x = 0;
    int y = 0; 
    vector<pair<int, int>> next_state(const pair<int, int> & s) {
        vector<pair<int, int>> result; 
        result.push_back(make_pair(0, s.second));
        result.push_back(make_pair(s.first, 0));
        result.push_back(make_pair(x, s.second));
        result.push_back(make_pair(s.first, y));
        int pull = min(s.second, x-s.first);
        result.push_back(make_pair(s.first+pull, s.second-pull));
        pull = min(s.first, y-s.second);
        result.push_back(make_pair(s.first-pull, s.second+pull));
    }
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false; 
        if (z < 0) return false;
        this->x = x;
        this->y = y;
        stack<pair<int, int>> stk; 
        stk.push(make_pair(0, 0)); 
        unordered_set<pair<int, int>, Hash_pair, Equal_pair> discovered;
        discovered.insert(make_pair(0, 0)); 
        while (!stk.empty()) {
            auto state = stk.top(); stk.pop();
            if (state.first + state.second == z) return true; 
            auto nexts = next_state(state); 
            for (auto n : nexts) {
                if (n.first <= x && n.second <= y && discovered.find(n) == discovered.end()) {
                    stk.push(n); 
                    discovered.insert(n);
                }
            }
        }
        return false; 
    }
};