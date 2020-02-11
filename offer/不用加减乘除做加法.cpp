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
    int Add(int num1, int num2)
    {
        int add = num1 ^ num2;
        int plus = (num1 & num2) << 1;
        while (plus) {
            int tmp = add ^ plus;
            plus = (add & plus) << 1;
            add = tmp;
        }
        return add;
    }
};

// class Solution {
// public:
//     int Add(int num1, int num2)
//     {
//         return num2 ? Add(num1^num2, (num1&num2)<<1) : num1;
 
//     }
// };