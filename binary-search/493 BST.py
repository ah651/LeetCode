class Solution:
    '''
    Binary Search Tree version
    '''
    class Node:
        def __init__(self, val, cnt):
            self.val = val 
            self.cnt = cnt 
            self.left = None 
            self.right = None 
    
    def search(self, root, val):
        if root.val == val:
            return root.cnt 
        if root.val > val:
            if root.left:
                return root.cnt+self.search(root.left, val)
            else:
                return root.cnt 
        else:
            if root.right:
                return self.search(root.right, val)
            else:
                return 0 

    def insert(self, root, val):
        if root.val == val:
            root.cnt += 1
            return 
        if root.val > val:
            if root.left:
                self.insert(root.left, val)
            else:
                root.left = self.Node(val, 1)
        else:
            root.cnt += 1
            if root.right:
                self.insert(root.right, val)
            else:
                root.right = self.Node(val, 1)
    

    def reversePairs(self, nums) -> int:
        if len(nums) <= 1:
            return 0 
        result = 0
        root = self.Node(nums[0], 0)
        for num in nums:
            result += self.search(root, num*2+1)
            self.insert(root, num)
        return result