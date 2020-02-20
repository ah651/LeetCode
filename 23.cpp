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
struct cmp {
    bool operator()(const ListNode * a, const ListNode * b) const {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        ListNode * result = new ListNode(-1);
        ListNode * cur = result;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }
        while (!pq.empty()) {
            ListNode * tmp = pq.top(); pq.pop();
            cur->next = tmp;
            cur = tmp;
            if (tmp->next) {
                pq.push(tmp->next);
            }
        }
        cur->next = nullptr;

        return result->next;
    }
};