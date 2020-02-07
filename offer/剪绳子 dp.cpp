#include <vector> 
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    int cutRope(int number) {
        // DP product[n] = max(product[i]*product[n-i])
        // [0-3] is special, not follow recursive formule
        if (number <= 1) {
            return 0;
        }
        if (number == 2) {
            return 1;
        }
        if (number == 3) {
            return 2;
        }
        vector<int> product(number+1);
        product[0] = 0;
        product[1] = 1;
        product[2] = 2;
        product[3] = 3;
        for(int i = 4; i < number+1; i++) {
            for (int j = 2; j < i/2+1; j++) {
                if (product[j]*product[i-j] > product[i]) {
                    product[i] = product[j]*product[i-j];
                }
            }
        }
        return product[number];
    }
};