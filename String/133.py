"""
# Definition for a Node.
class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
from collections import deque
class Solution:
    def cloneGraph(self, node: "Node") -> "Node":
        if node == None:
            return node 
        # construct all nodes without neibors
        d = {node.val: Node(node.val, [])}
        q = deque()
        q.append(node)
        while len(q) > 0:
            cur = q.popleft()
            for n in cur.neighbors:
                if n.val not in d:
                    q.append(n)
                    d[n.val] = Node(n.val, [])
        q = deque()
        q.append(node)
        dis_set = set()
        dis_set.add(node.val)
        while len(q) > 0:
            cur = q.popleft()
            for n in cur.neighbors:
                d[cur.val].neighbors.append(d[n.val])
                if n.val not in dis_set:
                    dis_set.add(n.val)
                    q.append(n)
        return d[node.val]                