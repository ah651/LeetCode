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
#include <cstring>
using namespace std;

#include <random>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // common method, use shift and bit operation
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            result |= ((n & 1 << i) >> i);
        }
        return result;
    }
};