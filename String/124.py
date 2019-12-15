# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        super().__init__()
        self.global_result = 0
    def maxPathSum(self, root: TreeNode) -> int:
        if root == None:
            return 0
        if root.left == None and root.right == None:
            return root.val
        self.global_result = root.val
        result = self.last_order(root)
        return self.global_result 

    def last_order(self, root: TreeNode):
        if root == None:
            return 0
        left = self.last_order(root.left)
        right = self.last_order(root.right)
        if max(root.val, root.val + left + right, root.val + left, root.val+right) > self.global_result:
            self.global_result = max(root.val, root.val + left + right, root.val + left, root.val+right)
        return max(root.val, root.val + max(left, right))

        # if root.val >= 0 and left >= 0 and right >= 0:
        #     tmp = root.val + left + right 
        #     if tmp > self.global_result:
        #         self.global_result = tmp
        #     return tmp
        # elif root.val >= 0:
        #     tmp = max(root.val, root.val+left, root.val+right)
        #     if tmp > self.global_result:
        #         self.global_result = tmp
        #     return tmp
        # else:
        #     tmp = max(root.val+left+right, root.val+left, root.val+right)
        #     if tmp > self.global_result:
        #         self.global_result = tmp
        #     return tmp
