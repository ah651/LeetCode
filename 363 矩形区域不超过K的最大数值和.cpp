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
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0; 
        int row = matrix.size(), col = matrix[0].size(); 
        int result = INT_MIN;
        for (int l = 0; l < col; l++) {
            vector<int> row_sum(row);
            for (int r = l; r < col; r++) {
                for (int i = 0; i < row; i++) {
                    row_sum[i] += matrix[i][r];
                }
                int tmp = row_sum[0], dp_i = row_sum[0];
                for (int i = 1; i < row; i++) {
                    dp_i = dp_i > 0? dp_i + row_sum[i] : row_sum[i]; 
                    tmp = dp_i > tmp? dp_i : tmp;
                }
                if (tmp == k) return tmp;
                else if (tmp < k && tmp > result) result = tmp; 
                else {
                    for (int i = 0; i < row; i++) {
                        tmp = 0; 
                        for (int j = i; j < row; j++) {
                            tmp += row_sum[j]; 
                            if (tmp <= k && tmp > result) {
                                result = tmp;
                            }
                        }
                    }
                    if (result == k) return k;
                }
            }
        }
        return result;
    }
};