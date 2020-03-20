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
using namespace std;
#include <random>

class Solution {
   public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        auto i = search(matrix, 0, matrix.size(), 0, matrix[0].size(), target);
        if (i == make_pair(-1, -1)) return false;
        return true;
    }

    pair<int, int> search(vector<vector<int>>& matrix, int rL, int rR, int cL, int cR, int target) {
        if ((rL > rR) || (cL > cR)) return make_pair(-1, -1);
        int rowL = rL;
        int colL = cL;
        int rowR = rR;
        int colR = cR;
        if (rowL == rowR && colL == colR) {
            if (matrix[rowL][colL] == target) {
                return make_pair(rowL, colL);
            } else {
                return make_pair(-1, -1);
            }
        }
        while (rowL <= rowR && colL <= colR) {
            int a = (rowL + rowR) / 2;
            int b = (colL + colR) / 2;
            if (matrix[a][b] == target) {
                return make_pair(a, b);
            } else if (matrix[a][b] > target) {
                auto one = search(matrix, rowL, a, colL, b, target);
                auto two = search(matrix, rowL, a - 1, b + 1, colR, target);
                auto three = search(matrix, a + 1, rowR, colL, b, target);
                auto fail = make_pair(-1, -1);
                if (one != fail) return one;
                if (two != fail) return two;
                if (three != fail) return three;
                return fail;

            } else {
                auto one = search(matrix, rowL, a - 1, b, colR, target);
                auto two = search(matrix, a + 1, rowR, colL, b, target);
                auto three = search(matrix, a, rowR, b + 1, colR, target);
                auto fail = make_pair(-1, -1);
                if (one != fail) return one;
                if (two != fail) return two;
                if (three != fail) return three;
                return fail;
            }
        }
        return make_pair(-1, -1);
    }
};