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
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result; 
        if (s.size() <= 10) return result; 
        set<int> check;
        set<string> result_s;
        // a little quicker
        vector<int> encoder(26);
        encoder['A'-'A'] = 0;
        encoder['C'-'A'] = 1;
        encoder['G'-'A'] = 2;
        encoder['T'-'A'] = 3;
        int tmp_key = 0;
        for (int i = 0; i < 10; i++) {
            tmp_key <<= 2; tmp_key |= encoder[s[i]-'A'];
        }
        tmp_key &= 0xfffff;
        check.insert(tmp_key);
        for (int i = 10; i < s.size(); i++) {
            tmp_key <<= 2; tmp_key |= encoder[s[i]-'A']; tmp_key &= 0xfffff;
            if (check.find(tmp_key) != check.end()) {
                result_s.insert(s.substr(i-9, 10));
            } else {
                check.insert(tmp_key);
            }
        }
        return vector<string>(result_s.begin(), result_s.end());
    }
};