#include <vector> 
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return vector<int>();
        }
        vector<int> result;
        int left = 0, right = matrix[0].size()-1;
        int top = 0, down = matrix.size()-1;
        while (left <= right && top <= down) {
            //left to right 
            int i = left;
            while (i <= right) {
                result.push_back(matrix[top][i]);
                i++;
            }
            // top to down 
            int j = top+1;
            while (j <= down) {
                result.push_back(matrix[j][right]);
                j++;
            }
            //right to left
            if (top < down) {
                i = right-1;
                while (i >= left) {
                    result.push_back(matrix[down][i]);
                    i--;
                }
            } 
            //down to top
            if (left < right) {
                j = down-1;
                while (j >= top+1) {
                    result.push_back(matrix[j][left]);
                    j--;
                }
            }
            
            top++; down--; left++; right--;
        }
        return result;
    }
};