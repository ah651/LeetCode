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
        '''
        bfs in-place
        '''
        if root == None:
            return root
        head = root 
        cur = root
        while cur.left != None:
            while cur != None:
                cur.left.next = cur.right
                if cur.next != None:
                    cur.right.next = cur.next.left
                cur = cur.next
            cur = head.left 
            head = cur

        return root

