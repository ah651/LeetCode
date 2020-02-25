#include <vector> 
#include <list>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
#include <climits>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

#include <random>

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 0 || num2.size() == 0 || num1 == "0" || num2 == "0") {
            return string("0");
        }
        string result("0");
        for (int i = num2.size()-1; i>=0; i--) {
            int int1 = num2[i]-'0';
            int carry = 0;
            string tmp;
            if (int1 == 0) {
                continue;
            } else {
                // make up 0
                for (int j = 0; j < num2.size()-i-1; j++) {
                    tmp += "0";
                }
                for (int j = num1.size()-1; j>=0 || carry > 0; j--) {
                    int int2 = (j>=0) ? num1[j] - '0' : 0;
                    tmp += (int1 * int2 + carry) % 10 + '0';
                    carry = (int1 * int2 + carry) / 10;
                }
                reverse(tmp.begin(), tmp.end());
                result = stringAdd(result, tmp);
            }
        }

        return result; 
    }

    string stringAdd(string a, string b) {
        string result; 
        int carry = 0;
        for (int i = a.size()-1, j = b.size()-1; i >= 0 || j >= 0 || carry > 0; i--, j--) {
            int inta = i>=0 ? a[i] - '0' : 0;
            int intb = j>=0 ? b[j] - '0' : 0;
            result += (inta + intb + carry) % 10 + '0';
            carry = (inta + intb + carry) / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};