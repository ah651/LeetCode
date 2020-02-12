#include <vector> 
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
#include <climits>
#include <set>
using namespace std;

#include <random>


class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (*str == '\0' && *pattern == '\0') {
            return true;
        } else if (*pattern == '\0') {
            return false;
        }
        if (*str == '\0') {
            if (*(pattern+1) == '*') {
                return match(str, pattern+2);
            } else {
                return false;
            }
        }
        // reguler match must traceback, so cann't solve by traverse.
        if (*(pattern + 1) == '*') {
            if (*str == *pattern || *pattern == '.') {
                return match(str+1, pattern) || match(str, pattern+2); 
            } else {
                return match(str, pattern+2);
            }
        } else {
            if (*str == *pattern || *pattern == '.') {
                return match(str+1, pattern+1);
            } else {
                return false;
            }
        }
    }
};