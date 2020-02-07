#include <vector> 
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;


class Solution {
public:
    int K;
    int movingCount(int threshold, int rows, int cols)
    {
        if (rows == 0 && cols == 0) {
            return 0;
        }
        if (threshold == 0) {
            return 1;
        }
        K = threshold;
        int cnt = 1;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue< pair<int, int>> q;
        q.push(make_pair(0, 0));
        visited[0][0] = true;
        while (!q.empty()) {
            //traverse for neibor
            pair<int, int> pos = q.front();
            q.pop();
            if ((pos.first-1) >= 0 and !visited[pos.first-1][pos.second] and check(pos.first-1, pos.second)) {
                cnt++;
                visited[pos.first-1][pos.second] = true;
                q.push(make_pair(pos.first-1, pos.second));
            }
            if ((pos.first+1) < rows and !visited[pos.first+1][pos.second] and check(pos.first+1, pos.second)) {
                cnt++;
                visited[pos.first+1][pos.second] = true;
                q.push(make_pair(pos.first+1, pos.second));
            }
            if ((pos.second-1) >= 0 and !visited[pos.first][pos.second-1] and check(pos.first, pos.second-1)) {
                cnt++;
                visited[pos.first][pos.second-1] = true;
                q.push(make_pair(pos.first, pos.second-1));
            }
            if ((pos.second+1) < cols and !visited[pos.first][pos.second+1] and check(pos.first, pos.second+1)) {
                cnt++;
                visited[pos.first][pos.second+1] = true;
                q.push(make_pair(pos.first, pos.second+1));
            }
        }
        return cnt;
    }
    bool check(int i, int j) {
        int a = 0;
        while (i != 0) {
            a += i % 10;
            i /= 10;
        }
        while (j != 0) {
            a += j % 10;
            j /= 10;
        }
        if (a <= K) {
            return true;
        } else {
            return false;
        }
    }
};