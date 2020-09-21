#include <iostream> 
#include <vector>
#include <stack>
#include <queue>
#include <map> 
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string> 
#include <cstdlib>
#include <algorithm>
#include <list> 
#include <deque>
#include <climits>

using namespace std; 

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0 || prerequisites.size() == 0) return true; 
        vector<vector<int>> adjs(numCourses, vector<int>());
        vector<int> in_degree(numCourses, 0); 
        for (auto edge: prerequisites) {
            int dst = edge[0];
            int src = edge[1];
            in_degree[dst]++; 
            adjs[src].push_back(dst);
        }
        queue<int> q; 
        int cnt = numCourses; 
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
                cnt--;
            }
        }
        while (q.size()) {
            int tmp = q.front(); q.pop();
            for(auto i: adjs[tmp]) {
                in_degree[i]--;
                if (!in_degree[i]) {
                    q.push(i);
                    cnt--;
                }
            }
        }
        return !cnt;

    }
};