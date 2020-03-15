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
    int cmp(int a, int b) {
        if (a == b) return 0; 
        else if (a > b) return -1; 
        else return 1;
    }
    int maxTurbulenceSize(vector<int>& A) {
        if (A.size() <= 1) return A.size(); 
        int result = 1; 
        int lo = 0;
        int i = 1;
        while (i < A.size() && A[i] == A[i-1]) {
            i++;
        }
        if (i == A.size()) return 1; 
        else result = 2;
        lo = i-1;
        for (; i < A.size(); i++) {
            if (i == A.size()-1 || cmp(A[i-1], A[i]) * cmp (A[i], A[i+1]) != -1) {
                result = i-lo+1 > result ? i-lo+1 : result; 
                if (i != A.size()-1) {
                    if (cmp(A[i], A[i+1])) {
                        lo = i;
                    } else {
                        lo = i+1;
                    }
                }
            }
        }
        return result;
    }
};