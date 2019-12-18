# Definition for a binary tree node.
from collections import deque
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root == None:
            return True 
        if root.left == None and root.right == None:
            return True 
        if root.left == None or root.right == None or root.left.val != root.right.val:
            return False 
        left_q = deque([root.left])
        right_q = deque([root.right])
        while len(left_q) != 0:
            l = left_q.popleft()
            r = right_q.popleft()
            if (l.left == None and r.right != None) or (l.left != None and r.right == None) or (l.right == None and r.left != None) or (l.right != None and r.left == None) or (l.val != r.val):
                return False 
            else:
                if l.left != None:
                    left_q.append(l.left)
                    right_q.append(r.right)
                if l.right != None:
                    left_q.append(l.right)
                    right_q.append(r.left)
        return True 
        