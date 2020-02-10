#include <vector> 
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
#include <climits>
#include <set>
using namespace std;

#include <random>


class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0) {
            return 0;
        }
        int cnt = 1;
        int proposal = 1;
        while (cnt <= index) {
            // check proposal is divisible by 2 3 5
            int tmp = proposal;
            while (tmp % 2 == 0) {
                tmp /= 2;
            }
            while (tmp % 3 == 0) {
                tmp /= 3;
            }
            while (tmp % 5 == 0) {
                tmp /= 5;
            }
            if (tmp == 1) {
                cnt++;
            }
            proposal++;
        }
        return proposal-1;
    }
};