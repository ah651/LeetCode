#include <iostream> 
#include <string> 
#include <vector> 
#include <unordered_map>
#include <queue> 
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
    int result = 0;
    int minCameraCover(TreeNode* root) {
        result = 0; 
        if (dfs(root) == 0) {
            result++;
        }

        return result;
    }
    // 3 state: 0, not cover; 1, cover, no cam; 2, cover and cam
    int dfs(TreeNode * root) {
        if (!root) {
            return 1;
        }
        int l = dfs(root->left); 
        int r = dfs(root->right); 
        if (l == 0 || r == 0) {
            result++; 
            return 2;
        } else if (l == 2 || r == 2) {
            return 1;
        } else {
            return 0;
        }
    }
};