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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr; 
        ListNode * tmpa = headA, * tmpb = headB; 
        while (tmpa && tmpb) {
            tmpa = tmpa->next;
            tmpb = tmpb->next;
        }      
        ListNode * a = headA, * b = headB;
        while (tmpa) {
            tmpa = tmpa->next; a = a->next;
        }
        while (tmpb) {
            tmpb = tmpb->next; b = b->next;
        }
        while (a && a != b) {
            a = a->next; b = b->next;
        }
        return a ? a :nullptr;
    }
};