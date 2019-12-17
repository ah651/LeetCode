# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        super().__init__()
        self.flag = True 
    def isValidBST(self, root: TreeNode) -> bool:
        if root == None:
            return True 
        if root.left == None and root.right == None:
            return True 
        self.flag = True 
        self.in_order(root)
        return self.flag
    def in_order(self, root: TreeNode):
        if root == None:
            return []
        left = self.in_order(root.left)
        if len(left) > 0 and left[-1] >= root.val:
            self.flag = False 
        
        right = self.in_order(root.right)
        if len(right) > 0 and root.val >= right[0]:
            self.flag = False
        return left + [root.val] + right 