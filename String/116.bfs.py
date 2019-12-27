"""
# Definition for a Node.
class TreeNode:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
from collections import deque
class Solution:
    def connect(self, root):
        if root == None:
            return root
        i = 0
        q = deque()
        q.append(root)
        while len(q) != 0:
            pre_node = q.popleft()
            if pre_node.left != None:
                q.append(pre_node.left)
                q.append(pre_node.right)
            for j in range(2**i-1):
                cur_node = q.popleft()
                if cur_node.left != None:
                    q.append(cur_node.left)
                    q.append(cur_node.right)
                pre_node.next = cur_node
                pre_node = cur_node
            i += 1
        return root


