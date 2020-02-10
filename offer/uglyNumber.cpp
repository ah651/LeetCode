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
        vector<int> result(index);
        result[0] = 1;
        int idx2 = 0, idx3 = 0, idx5 = 0;
        int cnt = 1;
        while (cnt < index) {
            int m2 = result[idx2] * 2;
            int m3 = result[idx3] * 3;
            int m5 = result[idx5] * 5;
            int tmp = getMin(m2, m3, m5);
            result[cnt] = tmp;
            while (result[idx2] * 2 <= tmp) {
                idx2++;
            }
            while (result[idx3] * 3 <= tmp) {
                idx3++;
            }
            while (result[idx5] * 5 <= tmp) {
                idx5++;
            }
            cnt++;
        }
        return result.back();
    }
    int getMin(int n2, int n3, int n5) {
        if (n2 <= n3 && n2 <= n5) {
            return n2;
        } else if (n3 <= n2 && n3 <= n5) {
            return n3;
        } else {
            return n5;
        }
    }
};