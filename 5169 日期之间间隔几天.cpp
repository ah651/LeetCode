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
        int days[12] = {31,28, 31,30,31,30,31,31,30,31,30,31};
        int year1 = stoi(date1.substr(0, 4)), month1 = stoi(date1.substr(5,2)), day1 = stoi(date1.substr(8, 2));
        int year2 = stoi(date2.substr(0, 4)), month2 = stoi(date2.substr(5,2)), day2 = stoi(date2.substr(8, 2));
        if ((year1 == year2 && month1 == month2 && day1 == day2)) {
            return 0;
        }
        if (year1 > year2 || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2)) {
            int tmp1 = year1, tmp2 = month1, tmp3 = day1;
            year1 = year2, month1 = month2, day1 = day2;
            year2 = tmp1, month2 = tmp2, day2 = tmp3;
        }
        int cnt = 0;
        //middle
        if (year2 - year1 > 1) {
            cnt += 365 * (year2 - year1 - 1);
        }
        //leap year can only check by traverse all years
        for (int i = year1+1; i < year2; i++) {
            if (i % 400 == 0) {
                cnt += 1;
            } else if (i % 100 != 0 && i % 4 == 0) {
                cnt += 1;
            }
        }
        if (year2 != year1) {
            //start year
            for (int i = month1; i < 12; i++) {
                cnt += days[i];
            }
            cnt += days[month1-1] - day1;
            if (year1 % 4 == 0 && year1 != 2100 && month1 <= 2) {
                cnt += 1;
            }
            //end year
            for (int i = 0; i < month2-1; i++) {
                cnt += days[i];
            }
            cnt += day2;
            if (year2 % 4 == 0 && year2 != 2100 && month2 > 2) {
                cnt += 1;
            }
        } else {
            if (month1 == month2) {
                cnt += day2 - day1;
            } else {
                for (int i = month1; i < month2-1; i++) {
                    cnt += days[i];
                }
                cnt += days[month1-1] - day1;
                cnt += day2;
                if (year1 % 4 == 0 && year1 != 2100 && month1 <= 2 && month2 > 2) {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};