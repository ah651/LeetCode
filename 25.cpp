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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) {
            return head;
        }
        return reverse(head, k);
    }
    ListNode * reverse(ListNode * head, int k) {
        ListNode * cur = head;
        stack<ListNode *> s;
        int i = 0;
        for (i = 0; i < k; i++) {
            if (!cur) {
                break;
            } else {
                s.push(cur);
                cur = cur->next;
            }
        }
        if (i < k) {
            return head;
        } else {
            ListNode * right = reverse(cur, k);
            ListNode * result = s.top(); s.pop();
            cur = result;
            while (!s.empty()) {
                ListNode * tmp = s.top(); s.pop();
                cur->next = tmp;
                cur = tmp;
            }
            cur->next = right;
            return result;
        }
    }
};