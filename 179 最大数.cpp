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

bool cmp(const string a, const string b) {
	if (a.size() == 0) {
		return false;
	}
	if (b.size() == 0) {
		return true;
	}
	int i = 0, j = 0;
	string a1 = a + b;
	string b1 = b + a;
	for (int i = 0; i < a1.size(); i++) {
		if (a1[i] < b1[i]) {
			return false;
		} else if (a1[i] > b1[i]) {
			return true;
		}
	}
	return false;
}

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		string result;
		if (nums.size() == 0) return result;
		vector<string> nums_s;
		for (auto i : nums) {
			nums_s.push_back(toString(i));
		}
		sort(nums_s.begin(), nums_s.end(), cmp);
		if (nums_s[0] == "0") return "0";
		for (auto s : nums_s) {
			result += s;
		}
		return result;
	}
	string toString(int a) {
		if (a == 0) return string("0");
		string result;
		while (a) {
			result += '0' + (a % 10);
			a /= 10;
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

