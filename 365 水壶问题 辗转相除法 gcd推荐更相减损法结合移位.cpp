#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <functional> 
using namespace std;
#include <random>

class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0) return b; 
        if (b == 0) return a;
        if (a < b) {
            int tmp = b;
            b = a; a = tmp;
        } 
        while (a % b != 0) {
            int tmp = a % b; 
            a = b; b = tmp;
        }
        return b;
    }
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0) return true; 
        if (z < 0) return false; 
        if (x + y < z) return false; 
        int c = gcd(x, y); 
        if (c == 0) return false; 
        if (z % c == 0) return true; 
        else return false;
    }
};