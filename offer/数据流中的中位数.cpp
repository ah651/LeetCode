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
    void Insert(int num)
    {
        if (cnt % 2 == 0) {
            big_queue.push(num);
            small_queue.push(big_queue.top());
            big_queue.pop();
        } else {
            small_queue.push(num);
            big_queue.push(small_queue.top());
            small_queue.pop();
        }
        cnt++;
    }

    double GetMedian()
    { 
        if (cnt % 2 == 0) {
            return (double(small_queue.top()) + double(big_queue.top())) / 2;
        } else {
            return double(small_queue.top());
        }
    }
    priority_queue<int, vector<int>, greater<int>> big_queue;
    priority_queue<int, vector<int>, less<int>> small_queue;
    int cnt = 0;

};