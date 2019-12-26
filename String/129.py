# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if root == None:
            return 0 
        return self.sum(root, [])
    
    def sum(self, root: TreeNode, path):
        if root == None:
            return self.generate_num(path)
        else:
            path.append(root.val)
            left, right = 0, 0
            if root.left == None and root.right == None:
                left = self.sum(root.left, path)
            else:
                if root.left != None:
                    left = self.sum(root.left, path)
                if root.right != None:
                    right = self.sum(root.right, path)
            path.pop()
            return left+right 

    def generate_num(self, path):
        num = 0 
        for i in path:
            num *= 10
            num += int(i)
        return num 