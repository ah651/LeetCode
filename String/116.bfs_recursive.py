#"""
# Definition for a Node.
class TreeNode:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
#"""
from collections import deque
class Solution:
    def connect(self, root):
        if root == None:
            return root
        if root.left != None:
            root.left.next = root.right
            if root.next != None:
                root.right.next = root.next.left 
        self.connect(root.left)
        self.connect(root.right)
        return root


