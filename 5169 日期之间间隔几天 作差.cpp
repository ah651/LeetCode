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
    int daysBetweenDates(string date1, string date2) {
        int year1 = stoi(date1.substr(0, 4)), month1 = stoi(date1.substr(5, 2)), day1 = stoi(date1.substr(8, 2));
        int year2 = stoi(date2.substr(0, 4)), month2 = stoi(date2.substr(5, 2)), day2 = stoi(date2.substr(8, 2));
        int a = dayFrom1971(year1, month1, day1);
        int b = dayFrom1971(year2, month2, day2);
        if (a >= b) return a-b;
        else return b-a;
    }
    int dayFrom1971(int year, int month, int day) {
        int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31,30, 31, 30, 31};
        int cnt = 0;
        for (int y = 1971; y < year; y++) {
            cnt += 365;
            if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)) {
                cnt++;
            }
        }
        for (int m = 1; m < month; m++) {
            cnt += days[m];
            if (m == 2 && (((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)))) {
                cnt += 1;
            }
        }
        cnt += day;
        return cnt;
    }
};