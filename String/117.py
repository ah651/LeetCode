"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root == None or (root.left==None and root.right==None):
            return root 
        
        cur = root
        if root.left:
            n_layer = root.left 
        else:
            n_layer = root.right
        while n_layer:
            #find next layers head
            cur = self.find_next(cur)
            if not cur:
                n_layer = None
                break 
            else:
                if cur.left:
                    n_layer = cur.left
                else:
                    n_layer = cur.right
                if cur.left and cur.right:
                        cur.left.next = cur.right
                        now = cur.right 
                elif cur.left:
                    now = cur.left
                else:
                    now = cur.right
                cur = cur.next
                cur = self.find_next(cur)
                while cur:
                    if cur.left:
                        now.next = cur.left
                    else:
                        now.next = cur.right
                        
                    if cur.left and cur.right:
                        cur.left.next = cur.right
                        now = cur.right 
                    elif cur.left:
                        now = cur.left
                    else:
                        now = cur.right
                    cur = cur.next
                    cur = self.find_next(cur)
                
                cur = n_layer

        return root
                


    def find_next(self, cur):
        '''
        find next node which has a child
        '''
        while cur:
            if cur.left or cur.right:
                return cur
            else:
                cur = cur.next 

        return None