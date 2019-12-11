# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if (p == None and q != None) or (p != None and q == None):
            return False

        if p == None and q == None:
            return True 
        queue_p = [p]
        queue_q = [q]
        # hierarchical search
        # compare p and q node, when node is poped
        while len(queue_p) != 0 and len(queue_p) == len(queue_q):
            layer_nums = len(queue_p)
            for i in range(layer_nums):
                p_node = queue_p.pop()
                q_node = queue_q.pop()
                if p_node.val == q_node.val:
                    if p_node.left == None:
                        if q_node.left != None:
                            return False 
                    if p_node.left != None:
                        if q_node.left == None:
                            return False 
                        else:
                            queue_p.append(p_node.left)
                            queue_q.append(q_node.left)
                    if p_node.right == None:
                        if q_node.right != None:
                            return False 
                    if p_node.right != None:
                        if q_node.right == None:
                            return False 
                        else:
                            queue_p.append(p_node.right)
                            queue_q.append(q_node.right)

                else:
                    return False
        return True 
