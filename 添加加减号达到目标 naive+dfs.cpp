#include <iostream>
#include <vector>
#include <string>

using namespace std;



// 2
// 11 2
// 12345 3
// 1 1
int result = 0;
vector<vector<int>> results;
enum choices {num, add, sub};
bool check(string & s, vector<int> & path, int target) {
    int a, b;
    int m = 0, n = 0;
    vector<int> nums; 
    while (n < s.size()) {
        if (path[n] == 0) {
            n++;
        } else {
            int tmp = 0; 
            while (m <= n) {
                tmp *= 10; tmp += s[m]-'0'; m++;
            }
            n++;
            nums.push_back(tmp);
        }
    }
    int tmp = 0; 
    while (m < n) {
        tmp *= 10; tmp += s[m]-'0'; m++;
    }
    nums.push_back(tmp);

    m = 0, n = 0;
    for (; n < path.size(); n++) {
        if (path[n] == 1) {
            m++; 
            nums[m] = nums[m-1] + nums[m];
        } else if (path[n] == 2) {
            m++;
            nums[m] = nums[m-1] - nums[m];
        }
    }
    if (nums.back() == target) return true; 
    else return false;

}

void dfs(string &s, vector<int> & path, int pos, int target) {
    if (pos == s.size()-1) {
        if (check(s, path, target)) {
            result++;
            results.push_back(path);
        }
    } else {
        int origin = path[pos]; 
        path[pos] = 0; 
        dfs(s, path, pos+1, target);
        path[pos] = 1; 
        dfs(s, path, pos+1, target);
        path[pos] = 2; 
        dfs(s, path, pos+1, target);
        path[pos] = origin;
    }
}

int main() {
    int T; cin >> T; 
    while (T) {
        string s; cin >> s;
        int target; cin >> target;
        result = 0; results.clear();
        vector<int> path(s.size(), -1);
        path.back() = 0; 
        dfs(s, path, 0, target);
        cout << result << endl;
        T--;
    }


    return 0; 
}