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
    void rotate(vector<int>& nums, int k) {
        //rotate at place
        if (k % nums.size() == 0) return;
        int cnt = 0;
        int first = 0;
        int pos = first;
        int pre = nums[pos];
        while (cnt < nums.size()) {
            int tmp = nums[(pos + k) % nums.size()];
            nums[(pos + k) % nums.size()] = pre;
            pre = tmp;
            pos = (pos + k) % nums.size(); 
            if (pos == first) {
                pos++; first = pos; pre = nums[pos];
            }
            cnt++;
        }
    }
};