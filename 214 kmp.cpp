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
    string shortestPalindrome(string s) {
        if (s.size() <= 1) return s; 
        string s1 = s; reverse(s1.begin(), s1.end());
        s1 = s + '#' + s1;
        vector<int> n(s1.size()+1, 0);
        int i = 0, j = -1;
        n[0] = -1;
        while (i < s1.size()) {
            if (j == -1 || s1[i] == s1[j]) {
                i++; j++;
                n[i] = j;
            } else {
                j = n[j];
            }
        }
        string a = s.substr(n[s1.size()], s.size()-n[s1.size()]);
        reverse(a.begin(), a.end());
        return a+s;
    }
};