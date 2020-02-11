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
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        // seperate data into two array
        int andOfData = 0;
        for (auto i : data) {
            andOfData ^= i;
        }
        //get last 1 in xor result
        int seperate = andOfData & (-andOfData);
        vector<int> d1, d2;
        for (auto i : data) {
            if (i&seperate) {
                d1.push_back(i);
            } else {
                d2.push_back(i);
            }
        }
        int tmp1 = 0, tmp2 = 0;
        for (auto i : d1) {
            tmp1 ^= i;
        }
        for (auto i : d2) {
            tmp2 ^= i;
        }
        *num1 = tmp1;
        *num2 = tmp2;
    }
};