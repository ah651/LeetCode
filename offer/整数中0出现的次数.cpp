#include <vector> 
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
    int NumberOf0Between1AndN_Solution(int n)
    {
        int cnt = 0;
        int i = 1;
        int k = n / i;
        while (k / 10) {
            //higher position (k/10)
            cnt += k/10 * i;
            //current position: k%10, lower position: n - k*i
            if (k % 10 == 0) {
                cnt += n - k*i + 1 - i;
            }
            i *= 10;
            k = n / i;
        }
        return cnt;
    }
};