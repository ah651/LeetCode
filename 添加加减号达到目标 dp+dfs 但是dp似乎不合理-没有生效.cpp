#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;



// 2
// 11 2
// 12345 3
// 1 1
int result = 0;
vector<vector<int>> results;

struct hasher {
    size_t operator()(const pair<int, int> & p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};
struct cmper {
    bool operator()(const pair<int, int> & a, const pair<int, int> & b) const {
        return a.first == b.first && a.second == b.second;
    }
};

unordered_map<pair<int, int>, int, hasher, cmper> records;
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

int dfs(string &s, int pos, int target) {
    if (pos == s.size()-1) {
        if (target == s.back()-'0') {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (records.find(make_pair(pos, target)) != records.end()) {
            return records[make_pair(pos, target)];
        }
        int tmp_result = 0;
        int tmp = 0; 
        for (int i = pos; i < s.size()-1; i++) {
            tmp *= 10; tmp += s[i]-'0';
            tmp_result += dfs(s, i+1, target-tmp);
            tmp_result += dfs(s, i+1, tmp-target);
        }
        tmp *= 10; tmp += s.back()-'0';
        if (tmp == target) {
            tmp_result++;
        }
        return tmp_result;
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
        result = dfs(s, 0, target);
        cout << result << endl;
        T--;
    }


    return 0; 
}