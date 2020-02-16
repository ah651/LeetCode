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

bool cmp(const vector<int> & a, const vector<int> & b) {
    if (a[1] != b[1]) {
        return a[1] < b[1];
    } else {
        return a[0] < b[0];
    }
}

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        if (events.size() == 0) {
            return 0;
        }        
        sort(events.begin(), events.end(), cmp);
        map<int, bool> used;
        int cnt = 0;
        for (auto e: events) {
            if (used.count(e[0]) == 0) {
                cnt++; used[e[0]] = true;
            } else {
                for(auto i = e[0]; i <= e[1]; i++) {
                    if (used.count(i) == 0) {
                        cnt++; used[i] = true; break;
                    }
                }
            }
        }
        return cnt;
    }
};
