#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
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
using namespace std;
#include <random>


class Solution {
public:
    bool is_hw(const string & s) {
        int lo = 0, hi = s.size()-1; 
        while (lo < hi) {
            if (s[lo] != s[hi]) return false; 
            lo++; hi--;
        }
        return true;
    }

    vector<string> suffix(string & s) {
        vector<string> result; 
        for (int i = 0; i < s.size(); i++) {
            if (is_hw(s.substr(0, i+1))) {
                result.push_back(s.substr(i+1, s.size()-i-1));
            }
        }
        return result;
    }

    vector<string> prefix(string & s) {
        vector<string> result; 
        for (int i = 0; i < s.size(); i++) {
            if (is_hw(s.substr(i, s.size()-i))) {
                result.push_back(s.substr(0, i));
            }
        }

        return result;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> m;
        for(int i = 0; i < words.size(); i++) {
            string s = words[i]; reverse(s.begin(), s.end());
            m[s] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            string s = words[i]; 
            if (m.count(s)) {
                if (i != m[s])
                result.push_back(vector<int>{i, m[s]});
            }
            vector<string> a = suffix(s);
            for (auto t : a) {
                if (m.count(t)) {
                    result.push_back(vector<int>{m[t], i});
                }
            }
             a = prefix(s);
            for (auto t : a) {
                if (m.count(t)) {
                    result.push_back(vector<int>{i, m[t]});
                }
            }
        }
        return result;
    }
};