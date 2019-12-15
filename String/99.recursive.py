# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root == None:
            return
        if root.left == None and root.right == None:
            return 
        
        in_order = self.in_order_traversal(root)
        for i in range(len(in_order)-1):
            if in_order[i].val > in_order[i+1].val:
                break 
        for j in range(len(in_order)-1, 0, -1):
            if in_order[j].val < in_order[j-1].val:
                break 
        if in_order[i].val <= in_order[i+1].val:
            return 
        tmp = in_order[i].val 
        in_order[i].val = in_order[j].val 
        in_order[j].val = tmp 


    def in_order_traversal(self, root):
        if root == None:
            return []
        left = self.in_order_traversal(root.left)
        right = self.in_order_traversal(root.right)
        return left + [root] + right