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
#include <unordered_map>
#include <cstring>
using namespace std;
#include <random>

class Solution {
public:
    int findNthDigit(int n) {
        if (n == 0) return 0;
        int cnt = 0; long long exp = 1; int length = 1;
        while (true) {
            if (9*exp*length+cnt < n) {
                cnt += 9*exp*length; exp *= 10; length++;
            } else {
                cnt = (n - cnt); 
                int number = (cnt-1) / length;
                number = exp+number;
                int idx = cnt % length;
                //这种从头开始计数的老老实实先转成str再说
                string result = to_string(number);
                if (idx == 0) return result.back()-'0';
                else return result[idx-1]-'0';
            }
        }
        return -1;
    }
};