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

struct bigger{
    bool operator()(const pair<int, pair<int, int>> & a, const pair<int, pair<int, int>> & b) const {
        int m = a.first + a.second.first;
        int n = b.first + b.second.first;
        return m > n;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result; 
        if (nums1.size() == 0 || nums2.size() == 0) return result;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, bigger> pq;
        for (int i = 0; i < nums1.size() && i < k; i++) {
            pq.push(make_pair(nums1[i], make_pair(nums2[0], 0)));
        }
        for (int i = 0; i < k && pq.size(); i++) {
            auto tmp = pq.top(); pq.pop();
            result.push_back(vector<int>{tmp.first, tmp.second.first});
            if (tmp.second.second+1 < nums2.size()) {
                pq.push(make_pair(tmp.first, make_pair(nums2[tmp.second.second+1], tmp.second.second+1)));
            }
        }
        return result;
    }
};