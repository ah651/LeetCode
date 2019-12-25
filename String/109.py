# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sortedListToBST(self, head) -> TreeNode:
        if head == None:
            return None
        nums = []
        while head != None:
            nums.append(head.val)
            head = head.next
        return self.bst(nums, 0, len(nums))

    def bst(self, nums, lo, hi):
        if lo >= hi:
            return None 
        if hi-lo == 1:
            return TreeNode(nums[lo])
        mi = (lo+hi)//2
        left = self.bst(nums, lo, mi)
        right = self.bst(nums, mi+1, hi)
        r = TreeNode(nums[mi])
        r.left = left 
        r.right = right 
        return r 