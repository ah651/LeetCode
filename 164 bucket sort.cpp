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

struct Bucket {
    Bucket(int a, int b) : min(a), max(b) {}
    int min = INT_MAX;
    int max = INT_MIN;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // bucket sort
        if (nums.size() < 2) return 0;
        int min = INT_MAX, max = INT_MIN;
        for (auto i : nums) {
            min = i < min? i : min;
            max = i > max? i : max;
        }
        int bucket_size = (max - min) / (nums.size() - 1) > 0? (max - min) / (nums.size() - 1) : 1;
        int bucket_cnt = (max - min) / bucket_size + 1;
        vector<Bucket *> buckets(bucket_cnt);
        for (auto i : nums) {
            int idx = (i - min) / bucket_size;
            if (buckets[idx]) {
                buckets[idx]->min = buckets[idx]->min < i ? buckets[idx]->min : i;
                buckets[idx]->max = buckets[idx]->max > i ? buckets[idx]->max : i;
            } else {
                buckets[idx] = new Bucket(i, i);
            }
        }
        int result = 0;
        int pre_max = INT_MAX; 
        for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i]) {
                if (pre_max != INT_MAX) {
                    result = buckets[i]->min - pre_max > result ? buckets[i]->min - pre_max : result;
                    pre_max = buckets[i]->max;
                }
                pre_max = buckets[i]->max;

                //result = buckets[i]->max - buckets[i]->min > result ? buckets[i]->max - buckets[i]->min : result;
            }
        }
        return result; 
    }
};