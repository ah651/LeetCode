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
    //hash and dict-tree(tire-tree) are interchangeable
    struct Node {
        Node * children[26];
        vector<int> words;
        vector<int> suffixs;
        Node() {
            words.clear(); suffixs.clear();
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    void insert(Node * root, string & s, int p) {
        Node * cur = root;
        if (is_hw(s, 0)) {
            root->suffixs.push_back(p);
        } 
        for (int i = 0; i < s.size(); i++) {
            if (cur->children[s[i]-'a'] == nullptr) {
                cur->children[s[i]-'a'] = new Node();
            }
            cur = cur->children[s[i]-'a'];
            if (i != s.size()-1 && is_hw(s, i+1)) {
                cur->suffixs.push_back(p);
            }
        }
        cur->words.push_back(p);
    }

    void select(Node * root, string & s, int p, vector<vector<int>> & result) {
        Node * cur = root;
        if (s.empty()) {
            for (auto i : cur->suffixs) {
                if (p != i){
                    result.push_back(vector<int>{p, i});
                    result.push_back(vector<int>{i, p});
                }
            }
            return;
        } 
        for (int i = 0; i < s.size(); i++) {
            cur = cur->children[s[i]-'a'];
            if (cur == nullptr) {
                return;
            }
            if (is_hw(s, i+1)) {
                for (auto j : cur->words) {
                    if (p != j)
                    result.push_back(vector<int>{p, j});
                }
            }
        }
        for (auto j: cur->suffixs) {
            if (j != p)
            result.push_back(vector<int>{p, j});
        }
    }

    bool is_hw(string & s, int p) {
        int lo = p, hi = s.size()-1;
        while (lo < hi) {
            if (s[lo] != s[hi]) return false;
            else {
                lo++; hi--;
            }
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        if (words.size() <= 1) return result;
        root = new Node();
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            reverse(s.begin(), s.end());
            insert(root, s, i);
        }

        for (int i = 0; i < words.size(); i++) {
            select(root, words[i], i, result);
        }

        delete root;
        return result;
    }
    Node * root;
    
};