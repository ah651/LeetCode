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
    ListNode* reverseList(ListNode* head) {
        // recursive method: a_k+1 is ok, a_k->next = a_k+1
        // solve a->next
        if (!head || !head->next) return head;
        ListNode * result = reverseList(head->next);
        head->next->next = head; 
        head->next = nullptr;
        return result; 
        
    }
};