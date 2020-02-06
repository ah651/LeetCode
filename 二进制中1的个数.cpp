#include <vector> 
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
     int  NumberOf1(int n) {
        int cnt = 0;
        while (n != 0) {
            cnt++;
            n &= (n-1);
        } 
        return cnt;
     }
};