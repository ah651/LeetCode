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

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) {
            return result;
        }
        vector<int> path; 
        sort(nums.begin(), nums.end());
        vector<int> remains(nums.begin(), nums.end());
        permute(result, path, remains);
        return result;
    }
    void permute(vector<vector<int>> & result, vector<int> & path, vector<int> & remains) {
        if (remains.empty()) {
            result.push_back(vector<int>(path));
        } else {
            for (int i = 0; i < remains.size(); i++) {
                if (i == 0 || remains[i] != remains[i-1]) {
                    path.push_back(remains[i]); 
                    vector<int> remains_tmp(remains);
                    remains_tmp.erase(remains_tmp.begin() + i);
                    permute(result, path, remains_tmp);
                    path.pop_back();
                }
            }
        }
    }
};