#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

//()()()((()))(()())

//it's a down to top solution, wright

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

void dfs(string& s, vector<int>& match, int lo, int hi, vector<vector<vector<vector<long long > > > > & dp) {
    if (lo+1 == hi) {
        dp[lo][hi][0][1] = 1;
        dp[lo][hi][0][2] = 1;
        dp[lo][hi][1][0] = 1;
        dp[lo][hi][2][0] = 1;
        return;
    } else {

        if (match[lo] == hi) {
            dfs(s, match, lo+1, hi-1, dp);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (j != 1) {
                        dp[lo][hi][0][1] += dp[lo+1][hi-1][i][j];
                        dp[lo][hi][0][1] %= int(1e9+7);
                    }
                    if (j != 2) {
                        dp[lo][hi][0][2] += dp[lo+1][hi-1][i][j];
                        dp[lo][hi][0][2] %= int(1e9+7);
                    }
                    if (i != 1) {
                        dp[lo][hi][1][0] += dp[lo+1][hi-1][i][j];
                        dp[lo][hi][1][0] %= int(1e9+7);
                    }
                    if (i != 2) {
                        dp[lo][hi][2][0] += dp[lo+1][hi-1][i][j];
                        dp[lo][hi][2][0] %= int(1e9+7);
                    }
                }
            }
            return;
        } else {
            int tmp = match[lo];
            dfs(s, match, lo, tmp, dp);
            dfs(s, match, tmp+1, hi, dp);
            for (int loc = 0; loc < 3; loc++) {
                for (int hic = 0; hic < 3; hic++) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            //if ((loc == 0 && i == 0) || (hic == 0 && j == 0)) continue;
                            if (!((i == 1 && j == 1) || (i == 2 && j ==2))) {
                                dp[lo][hi][loc][hic] = (dp[lo][hi][loc][hic] + ((dp[lo][tmp][loc][i]%int(1e9+7))*(dp[tmp+1][hi][j][hic]%int(1e9+7)))%int(1e9+7))%int(1e9+7);
                            }
                        }
                    }

                }
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    long long result = 0;
    vector<int> match = bucket_match(s);
    vector<vector<vector<vector<long long > > > > dp(s.size(), vector<vector<vector<long long > > >(s.size(), vector<vector<long long > >(3, vector<long long>(3,0))));
    dfs(s, match, 0, s.size()-1, dp);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (dp[0][s.size()-1][i][j] > 0) {
            result += dp[0][s.size()-1][i][j];
            result %= int(1e9+7);
            }
        }
    }

    cout << result;
    return 0;
}
