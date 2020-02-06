#include <vector> 
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() == 0) {
            return nullptr;
        }
        return constructTree(pre, vin, 0, 0, pre.size());
    }
    TreeNode * constructTree(vector<int> & pre, vector<int> & vin, int pL, int iL, int Len) {
        if (Len == 0) {
            return nullptr;
        }
        int root_val = pre[pL];
        int root_in_vin = find(vin.begin(), vin.end(), root_val) - vin.begin();
        int left_length = root_in_vin - iL;
        int right_length = Len - (root_in_vin - iL) - 1;
        TreeNode * left_node = constructTree(pre, vin, pL+1, iL, left_length);
        TreeNode * right_node = constructTree(pre, vin, pL+1+left_length, root_in_vin+1, right_length);
        TreeNode * root = new TreeNode(root_val);
        root->left = left_node;
        root->right = right_node;
        return root;
    }
};