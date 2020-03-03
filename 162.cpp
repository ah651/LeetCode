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
    int findPeakElement(vector<int>& nums) {
        //a[i] != a[i+1], so peek must exist
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i+1]) {
                return i;
            }
        }
        return nums.size()-1;
    }
};