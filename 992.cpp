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
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int a = noMoreThan(A, K);
        int b = noMoreThan(A, K-1);
        return a-b;
    }
    int noMoreThan(vector<int>& s, int k) {
        int lo = 0, hi = 0;
        int distinct = 0;
        int cnt[20000] = {0}; 
        int result = 0; 
        while (hi < s.size()) {
            if (cnt[s[hi]] == 0) {
                distinct++;
            }
            cnt[s[hi]]++; 
            while (distinct > k) {
                cnt[s[lo]]--;
                if (cnt[s[lo]] == 0) {
                    distinct--;
                }
                lo++;
            }
            result += hi-lo+1;

            hi++;
        }
        return result;
    }
};