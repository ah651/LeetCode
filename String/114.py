# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        First order
        """
        if root == None:
            return 
        dummy = TreeNode(-1)
        dummy.right = root 
        self.first_order(root, dummy)
        self.last = None 
    def first_order(self, root: TreeNode, pre: TreeNode):
        self.last = root 
        pre.left = None
        pre.right = root 
        pre = root 
        tmp_r = root.right
        if root.left:
            self.first_order(root.left, pre)
        if tmp_r:
            self.first_order(tmp_r, self.last)