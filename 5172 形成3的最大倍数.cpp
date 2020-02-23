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
    string largestMultipleOfThree(vector<int>& digits) {
        if (digits.size() == 0) {
            return string();
        }
        sort(digits.begin(), digits.end());
        reverse(digits.begin(), digits.end());
        int sum = 0;
        for (auto i : digits) {
            sum += i;
        }
        if (digits[0] == 0) {
            return string("0");
        }
        int remove1 = -1, remove2 = -1;
        if (sum % 3 == 1) {
            int i = digits.size()-1;
            while (i >= 0) {
                if (digits[i] % 3 == 1) {
                    remove1 = i;               
                    break;
                }
                i--;
            }
            if (i == -1) {
                i = digits.size()-1;
                while (i >= 0) {
                    if (remove1 == -1 && digits[i] % 3 == 2) {
                        remove1 = i;               
                    } else if (digits[i] % 3 == 2) {
                        remove2 = i;
                        break;
                    }
                    i--;
                }
                
            }
        } else if (sum % 3 == 2) {
            int i = digits.size()-1;
            while (i >= 0) {
                if (digits[i] % 3 == 2) {
                    remove1 = i;               
                    break;
                }
                i--;
            }
            if (i == -1) {
                i = digits.size()-1;
                while (i >= 0) {
                    if (remove1 == -1 && digits[i] % 3 == 1) {
                        remove1 = i;               
                    } else if (digits[i] % 3 == 1) {
                        remove2 = i;
                        break;
                    }
                    i--;
                }
                
            }

        }
        if (sum % 3 == 0) {
            return build(digits, remove1, remove2);
        } else {
            if (remove1 == -1) {
                return string("0");
            } else {
                return build(digits, remove1, remove2);
            }
        }
    }
    string build(vector<int> & digits, int remove1, int remove2) {
        string result;
        for (int i = 0; i < digits.size(); i++) {
            if (i != remove1 && i != remove2) {
                result += digits[i] + '0';
            }
        }
        return result;
    }
};