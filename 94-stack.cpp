#include <iostream> 
#include <vector>
#include <stack>
#include <queue>
#include <map> 
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string> 
#include <cstdlib>
#include <algorithm>
#include <list> 
#include <deque>
#include <climits>

using namespace std; 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result; 
        TreeNode * cur = root;
        stack<TreeNode *> s; 
        while (s.size() || cur) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            auto tmp = s.top(); s.pop();
            result.push_back(tmp->val);
            cur = tmp->right;
        }
        return result;
    }
};