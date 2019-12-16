# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0 
        if root.left == None and root.right == None:
            return 1
        return self.depth(root)

    
    def depth(self, root: TreeNode):
        if root == None:
            return 0 
        left = self.depth(root.left)
        right = self.depth(root.right)
        return 1+max(left, right)