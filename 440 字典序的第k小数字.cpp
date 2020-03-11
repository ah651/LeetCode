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
    int min(int a, int b) {
        return a <= b? a : b;
    }
    int findKthNumber(int n, int k) {
        if (k > n) return -1; 
        int cnt = 0; 
        long long pre = 1; 
        while (cnt < k) {
            int tmp = childrenCnt(pre, n);
            if (cnt + tmp >= k) {
                pre *= 10; cnt++;
            } else {
                pre++; cnt += tmp;
            }
        }
        return pre/10;
    }
    int childrenCnt(int pre, int n) {
        int cnt = 0; 
        long long pre2 = pre;
        long long next = pre+1; 
        while (pre2 <= n) {
            cnt += min(next, n+1) - pre2; 
            next *= 10; pre2 *= 10; 
        }
        return cnt;
    }
};