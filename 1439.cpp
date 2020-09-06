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

struct bigger {
    bool operator()(const pair<int, vector<int>> & a, const pair<int, vector<int>> & b) const {
        return a.first > b.first;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        if (mat.size() == 0 || mat[0].size() == 0) return 0;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, bigger> pq;
        set<vector<int>> seen;
        int result = 0; 
        vector<int> pointer(mat.size(), 0);
        int tmp = 0; 
        for (int i = 0; i < mat.size(); i++) {
            tmp += mat[i][0];
        }
        pq.push(make_pair(tmp, pointer));
        seen.insert(pointer); 
        result = tmp; 
        int n = mat[0].size();
        int m = mat.size();
        for (int i = 0; i < k && pq.size(); i++) {
            auto tmp_p = pq.top(); pq.pop();
            int tmp_s = tmp_p.first; 
            result = tmp_s;
            auto tmp_ps = tmp_p.second;
            for (int j = 0; j < mat.size(); j++) {
                if (tmp_ps[j]+1 < n) {
                    int tmp1 = tmp_s - mat[j][tmp_ps[j]] + mat[j][tmp_ps[j]+1];
                    auto tmp2 = tmp_ps;
                    tmp2[j] = tmp_ps[j] + 1;
                    if (!seen.count(tmp2)) {
                        pq.push(make_pair(tmp1, tmp2));
                        seen.insert(tmp2);
                    }
                    
                }
            }
        }
        return result;
    }
};