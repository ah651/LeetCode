# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        return self.generateTree(inorder, postorder) 

    def generateTree(self, inorder, postorder):
        if len(inorder) == 0:
            return None 
        if len(inorder) == 1:
            return TreeNode(inorder[0])

        root_value = postorder[-1]
        root_index = -1
        for i in range(len(inorder)):
            if inorder[i] == root_value:
                root_index = i
                break 
        root = TreeNode(root_value)
        # have only one subtree
        if root_index == len(inorder)-1:
            root.left = self.generateTree(inorder[:root_index], postorder[:root_index])
            root.right = None 
        elif root_index == 0:
            root.left = None 
            root.right = self.generateTree(inorder[root_index+1:], postorder[root_index:-1])
        else:    
            root.left = self.generateTree(inorder[:root_index], postorder[:root_index])
            root.right = self.generateTree(inorder[root_index+1:], postorder[root_index:-1])
        return root 