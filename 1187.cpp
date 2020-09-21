#include <iostream> 
#include <string> 
#include <vector> 
#include <unordered_map>
#include <queue> 
#include <climits>


using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        if (arr1.size() == 0) return 0;
        sort(arr2.begin(), arr2.end()); 
        int lo = 0, hi = 1; 
        while (hi < arr2.size()) {
            while (hi < arr2.size() && arr2[hi] == arr2[hi-1]) {
                hi++;
            }
            if (hi < arr2.size()) {
                lo++; 
                arr2[lo] = arr2[hi];
                hi++;

            }
        }
        int N1 = arr1.size(); 
        int N2 = lo+1; 
        vector<vector<int>> dp(N1, vector<int>(N2+1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= N2; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < N1; i++) {
            // m, m
            for (int j = 2; j <= N2; j++) {
                if (dp[i-1][j-1] != INT_MAX)
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
            }
            //n, m
            int tmp = lower_bound(arr2.begin(), arr2.begin()+N2, arr1[i-1]+1) - arr2.begin() + 1;
            for (int j = tmp; j <= N2; j++) {
                if (dp[i-1][0] != INT_MAX)
                    dp[i][j] = min(dp[i][j], dp[i-1][0]+1);
            }
            //m, n
            tmp = lower_bound(arr2.begin(), arr2.begin()+N2, arr1[i]) - arr2.begin(); 
            for (int j = 1; j <= tmp && j <= N2; j++) {
                dp[i][0] = min(dp[i][0], dp[i-1][j]);
            }

            //n, n
            if (arr1[i-1] < arr1[i]) {
                dp[i][0] = min(dp[i][0], dp[i-1][0]);
            }
        }
        int result = INT_MAX; 
        for (int i = 0; i <= N2; i++) {
            result = min(result, dp[N1-1][i]);
        }
        if (result == INT_MAX) {
            return -1;
        } else {
            return result;
        }
    }
};