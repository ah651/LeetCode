#include <iostream> 
#include <vector>
#include <stack>
#include <queue>
#include <map> 
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string> 
#include <cstdlib>
#include <algorithm>
#include <list> 
#include <deque>
#include <climits>

using namespace std; 


class Solution {
public:
    vector<double> twoSum(int n) {
        vector<int> result(6*n+1, 0);

        for (int i = 1; i <= 6; i++) {
            result[i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            int lo = i, hi = 6*i;
            vector<int> result_tmp(6*n+1, 0);
            for (int j = 1; j <= 6; j++) {
                for (int k = lo; k <= hi; k++) {
                    if (k-j >= 1) 
                        result_tmp[k] += result[k-j];
                    //result_tmp[k] = max(1, result_tmp[k]);
                }
            }
            result = result_tmp;
        }
        vector<double> result2;
        result2.insert(result2.begin(), result.begin()+n, result.begin()+6*n+1);
        long long cnt = 1;
        for (int i = 0; i < n; i++) cnt *= 6;
        for (int i = 0; i < result2.size(); i++) {
            result2[i] /= cnt;
        }
        return result2;

    }
};