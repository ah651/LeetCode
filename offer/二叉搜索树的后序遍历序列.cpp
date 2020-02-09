#include <vector> 
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) {
            return false;
        }
        return verify(sequence, 0, sequence.size()-1);
    }
    bool verify(vector<int> & sequence, int lo, int hi) {
        if (lo > hi) {
            return true;
        }
        int root = sequence[hi];
        int mid = lo;
        while (sequence[mid] < root) {
            mid++;
        }
        int mid2 = mid;
        while (mid2 < hi) {
            if (sequence[mid2] < root) {
                return false;
            }
            mid2++;

        }
        bool left_check = verify(sequence, lo, mid-1);
        bool right_check = verify(sequence, mid, hi-1);
        if (left_check && right_check) {
            return true;
        } else {
            return false;
        }
    }
};