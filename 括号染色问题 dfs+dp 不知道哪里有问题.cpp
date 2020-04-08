#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

//(()()()((()))(()()))
//142560

//from top to down solution, why it is wrong?

enum color { white,
             red,
             blue };

vector<int> bucket_match(string& s) {
    stack<int> stk;
    vector<int> result(s.size(), 0);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            int top = stk.top();
            stk.pop();
            result[i] = top;
            result[top] = i;
        }
    }
    return result;
}
bool check(string& s, vector<int>& colors, vector<int>& match) {
    for (int i = 0; i < s.size() - 1; i++) {
        if ((colors[i] == 1 && colors[i + 1] == 1) || (colors[i] == 2 && colors[i + 1] == 2)) {
            return false;
        }
        if ((colors[i] == 0 && colors[match[i]] == 0) || colors[i] != 0 && colors[match[i]] != 0) {
            return false;
        }
    }
    return true;
}

int dfs(string& s, vector<int>& match, int lo, int hi, int loc, int hic, vector<vector<vector<vector<long long > > > > & dp) {
    if (lo+1 == hi) {
        if (loc == 0 && hic == 0) return 0;
        if (loc != 0 && hic != 0) return 0;
        return 1;
    } else {
        if (dp[lo][hi][loc][hic] != -1) return dp[lo][hi][loc][hic];

        long long result = 0;
        if (match[lo] == hi) {
            //if ((loc == 0 && hic == 0) || (loc != 0 && hic != 0)) return 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (loc == 0 && hic == 1 && j != 1) {
                        result += dfs(s, match, lo+1, hi-1, i, j, dp);
                        result %= int(1e9+7);
                    } else if (loc == 1 && hic == 0 && i != 1) {
                        result += dfs(s, match, lo+1, hi-1, i, j, dp);
                        result %= int(1e9+7);
                    } else if (loc == 0 && hic == 2 && j != 2) {
                        result += dfs(s, match, lo+1, hi-1, i, j, dp);
                        result %= int(1e9+7);
                    } else if (loc == 2 && hic == 0 && i != 2) {
                        result += dfs(s, match, lo+1, hi-1, i, j, dp);
                        result %= int(1e9+7);
                    }                    
                  
                }
            }
        } else {
            int tmp = match[lo];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    //if ((loc == 0 && i == 0) || (hic == 0 && j == 0)) continue;
                    if (!((i == 1 && j == 1) || (i == 2 && j ==2))) {
                        result += (((dfs(s, match, lo, tmp, loc, i, dp) % int(1e9+7))*(dfs(s, match, tmp+1, hi, j, hic, dp)% int(1e9+7))) % int(1e9+7));
                        result %= int(1e9+7);
                    }
                }
            }
        }
        dp[lo][hi][loc][hic] = (result % int(1e9+7));
        return dp[lo][hi][loc][hic];
    }
}

int main() {
    string s;
    cin >> s;
    long long result = 0;
    vector<int> match = bucket_match(s);
    vector<vector<vector<vector<long long > > > > dp(s.size(), vector<vector<vector<long long > > >(s.size(), vector<vector<long long > >(3, vector<long long>(3,-1))));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result += dfs(s, match, 0, s.size()-1, i, j, dp);
            result = result % int(1e9+7);
        }
    }
    cout << result;
    return 0;
}
