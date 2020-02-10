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
    int NumberOf1Between1AndN_Solution(int n, int x)
    {
        int cnt = 0;
        int i = 1;
        int k = n / i;
        while (k) {
            //higher position (k/10)
            cnt += k/10 * i;
            //current position: k%10, lower position: n - k*i
            if (k % 10 > x) {
                cnt += i;
            } else if (k % 10 == x) {
                cnt += n - k*i + 1;
            }
            i *= 10;
            k = n / i;
        }
        return cnt;
    }
};