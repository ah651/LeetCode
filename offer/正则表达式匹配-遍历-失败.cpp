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
        // reguler match must traceback, so cann't solve by traverse.
        // pre process
        int i = 0, j = 0;
        if (pattern[0] == '*') {
            return false;
        }
        if (pattern[0] == '.' && pattern[1] == '*' && pattern[2] == '\0') {
            return true;
        }
        while (pattern[i] != '\0') {
            if (pattern[i] == '*') {
                pattern[j] = pattern[i];
                i++; j++;
                while (pattern[i] != '\0' && pattern[i] == pattern[j-2]) {
                    i++;
                }
            } else {
                pattern[j] = pattern[i];
                i++; j++;
            }
        }
        pattern[j] = '\0';
        i = 0, j = 0;
        while (str[i] != '\0' && pattern[j] != '\0') {
            if (pattern[j+1] == '*') {
                if (pattern[j] != '.' && str[i] != pattern[j]) {
                    j += 2;
                } else {
                    if (pattern[j] == '.') {
                        int tmp = i;
                        while (str[i] != '\0' && str[i] == str[tmp]) {
                            i++;
                        }
                    } else {
                        while (str[i] != '\0' && str[i] == pattern[j]) {
                            i++;
                        }
                    }
                    j += 2;     
                }
            } else if (pattern[j] == '.') {
                i++; j++;
            } else {
                if (str[i] != pattern[j]) {
                    return false;
                } else {
                    i++; j++;       
                }
            }
        }
        if (pattern[j+1] == '*') {
            j += 2;
        }
        if (str[i] != '\0' || pattern[j] != '\0') {
            return false;
        } else {
            return true;
        }
    }
};