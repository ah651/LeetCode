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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result; 
        if (!root) return result;
        stack<TreeNode *> s; 
        s.push(root); 
        while (s.size()) {
            auto tmp = s.top(); s.pop();
            result.push_back(tmp->val);
            if (tmp->left) s.push(tmp->left);
            if (tmp->right) s.push(tmp->right);
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};