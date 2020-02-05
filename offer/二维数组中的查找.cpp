#include <vector> 
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        // search from top-right corner
        if (array.size() == 0 || array[0].size() == 0) {
            return false; 
        }
        int top = 0;
        int right = array[0].size()-1;
        while (top < array.size() && right >= 0) {
            if (array[top][right] > target) {
                right--;
            } else if (array[top][right] < target) {
                top++;
            } else {
                return true;
            }
        }
        return false;
    }
};