#include <vector> 
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
#include <climits>
#include <set>
using namespace std;

#include <random>

class Solution {
public:
    vector<int> dijiestra(vector<vector<int>> graph, int s) {
        //init
        vector<int> result(graph.size(), 999999);
        for (int i = 0; i < graph.size(); i++) {
            result[i] = graph[s][i];
        }
        set<int> check;
        check.insert(s);
        // add a point once
        while (check.size() < graph.size()) {
            //find shotest point to s min((s,v),(s,k)+(k,v))
            int tmp = -1;
            int distance = 999999;
            for (int i = 0; i < graph.size(); i++) {
                if (check.find(i) == check.end() && result[i] < distance) {
                    distance = result[i];
                    tmp = i;
                }
            }
            //update result
            for (int i = 0; i < graph.size(); i++) {
                if (result[tmp]+graph[tmp][i] < result[i]) {
                    result[i] = result[tmp]+graph[tmp][i];
                }
            }
            check.insert(tmp);
        }
        return result;
    }
    
};
