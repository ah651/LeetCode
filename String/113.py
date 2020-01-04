# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import copy
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if root == None:
            return []  
        self.result = []
        self.checkPathSum(root, sum, [])
        return self.result

    def checkPathSum(self, root: TreeNode, remain: int, path):
        # if remain < root.val:
        #     return False 
        if root.left == None and root.right == None:
            if root.val == remain:
                path.append(root.val)
                self.result.append(copy.deepcopy(path))
                path.pop()
             
        else:
            path.append(root.val)
            remain = remain-root.val
            if root.left:
                self.checkPathSum(root.left, remain, path)
            if root.right:
                self.checkPathSum(root.right, remain, path)
            path.pop()