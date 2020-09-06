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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result; 

        TreeNode * cur1 = root; 
        TreeNode * cur2 = nullptr; 
        while (cur1) {
            if (cur1->left) {
                cur2 = cur1->left; 
                while (cur2->right && cur2->right != cur1) {
                    cur2 = cur2->right;
                }
                if (cur2->right == nullptr) {
                    result.push_back(cur1->val);
                    cur2->right = cur1;
                    cur1 = cur1->left;
                    continue;
                } else {
                    cur2->right = nullptr;
                }
            } else {
                result.push_back(cur1->val);
            }
            cur1 = cur1->right;
        }
        return result;
    }
};