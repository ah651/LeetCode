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
    bool isMatch(string s, string p) {
        return match(s, p, 0, 0);
    }
    bool match(string & s, string & b, int si, int bi) {
        if (si == s.size() && bi == b.size()) {
            return true;
        } else if (bi == b.size()) {
            return false;
        }
        if (bi+1 < b.size() && b[bi+1] == '*') {
            bool nothing = match(s, b, si, bi+2);
            if (s.size() == si) {
                return nothing;
            }
            if (b[bi] == '.') {
                return nothing || match(s, b, si+1, bi);
            } else if (s[si] == b[bi]) {
                return nothing || match(s, b, si+1, bi);
            } else {
                return nothing;
            }
        } else {
            if (si == s.size()) {
                return false;
            }
            if (b[bi] == '.') {
                return match(s, b, si+1, bi+1);
            } else if (s[si] == b[bi]) {
                return match(s, b, si+1, bi+1);
            } else {
                return false;
            } 
        }
    }
};