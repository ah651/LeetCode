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
    vector<int> maxDepthAfterSplit(string seq) {
        result.clear(); 
        length = INT_MAX;
        for (int i = 0; i < seq.size(); i++) result.push_back(0);
        vector<int> tmp(result.begin(), result.end()); 
        dfs(seq, tmp, 0);
        return result;
    }
    vector<int> result;
    int length = INT_MAX;
    void dfs(string & seq, vector<int> & path, int pos) {
        if (pos == seq.size()) {
            int a = vps_len(seq, path);
            if (a != -1) {
                vector<int> path_tmp(path.begin(), path.end());
                for (int i = 0; i < path_tmp.size(); i++) {
                    if (path_tmp[i]) {
                        path_tmp[i] = 0;
                    } else {
                        path_tmp[i] = 1;
                    }
                }
                int b = vps_len(seq, path_tmp); 
                if (b != -1) {
                    int c = max(a, b); 
                    if (c < length) {
                        length = c;
                        result = path;
                    }
                }
            }
            return;
        }
        int tmp = path[pos]; 
        path[pos] = 0;
        dfs(seq, path, pos+1); 
        path[pos] = 1; 
        dfs(seq, path, pos+1); 
        path[pos] = tmp;
    }
    int vps_len(string & seq, vector<int> & sel) {
        string s; 
        for (int i = 0; i < sel.size(); i++) {
            if (sel[i]) {
                s += seq[i];
            }
        }
        //check is vps 
        int result = _vps_len(s);
        return result;
    }
    int _vps_len(string s) {
        if (s.size() == 0) return 0;
        if (s.size() % 2) return -1;
        int tmp = -1; 
        for (int i = 1; i < s.size(); i++) {
            int a = _vps_len(s.substr(0, i)); 
            if (a != -1) {
                int b = _vps_len(s.substr(i, s.size()-i));
                if (b != -1) {
                    tmp = tmp < max(a, b) ? max(a, b) : tmp;
                }
            }
        }
        if (s[0] == '(' && s.back() == ')' && s.size() >= 2) {
            int c = _vps_len(s.substr(1, s.size()-2));
            if (c != -1 && c > tmp) tmp = c+1;
        }
        return tmp;
    }
};