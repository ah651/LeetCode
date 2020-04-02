#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <functional> 
using namespace std;
#include <random>

class Solution {
public:
    int totalNQueens(int n) {
        if (n <= 0) return 0; 
        result = 0; 
        dfs(n, 0, 0, 0, 0);
        return result;
    }
    int result = 0;
    void dfs(int n, int pos, int col, int main_diag, int second_diag) {
        if (n == pos) {
            result++;
            return;
        } else {
            int proposal = ~(col | main_diag | second_diag) & (1 << n)-1;
            //int proposal = ~(col | main_diag | second_diag);
            while (proposal) {
                int slc = proposal & -proposal;
                dfs(n, pos+1, col | slc, (main_diag | slc) >> 1, (second_diag | slc) << 1);

                proposal &= (proposal - 1);
            }
        }
    }
};