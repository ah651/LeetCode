#include <vector> 
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    int result;
    int cutRope(int number) {
        if (number <= 1) {
            return 0;
        }
        if (number == 2) {
            return 1;
        }
        if (number == 3) {
            return 2;
        }
        result = 0; 
        return back_tracing(number, 1);
    }
    int back_tracing(int remain, int product) {
        if (remain == 2) {
            return product * remain;
        }
        //continue cut
        for(int i = 2; i < remain-1; i++) {
            int tmp = back_tracing(remain-i, product*i);
            if (tmp > result) {
                result = tmp;
            }
        }
        //stop cut
        if (product * remain > result) {
            result = product * remain;
        }
        return result;
    }
};