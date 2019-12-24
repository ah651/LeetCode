# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    '''
    dfs, down to top, one recursive
    '''
    def isBalanced(self, root: TreeNode) -> bool:
        if root == None:
            return True 
        if self.dfs_height(root) >= 0:
            return True 
        else:
            return False 
    
    def dfs_height(self, root: TreeNode) -> int:
        if root == None:
            return 0
        left = self.dfs_height(root.left)
        if left < 0:
            return -1
        right = self.dfs_height(root.right)
        if right < 0:
            return -1 
        if abs(left-right) > 1:
            return -1 
        else:
            return max(left, right)+1
