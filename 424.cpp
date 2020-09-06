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

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0; 
        int maxcnt = 0;
        int result = 0;
        int a[26] = {0};
        while (right < s.size()) {
            char tmp = s[right];
            a[tmp-'A']++;
            maxcnt = max(maxcnt, a[tmp-'A']);
            if (right-left+1 > maxcnt+k) {
                a[s[left]-'A']--;
                left++;
            }
            result = max(result, right-left+1);

            right++;
        }
        return right-left;
    }
};