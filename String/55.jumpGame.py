class Solution:
    def canJump(self, nums) -> bool:
        if len(nums) <= 1:
            return True 
        if nums[0] == 0:
            return False 
        if nums[0] >= len(nums)-1:
            return True 
        
        lo, hi = 1, nums[0]
        while hi < len(nums)-1:
            cur_hi = hi 
            for i in range(lo, hi+1):
                if i+nums[i] > cur_hi:
                    cur_hi = i+nums[i]
            if cur_hi <= hi:
                return False 
            lo, hi = hi+1, cur_hi


        return True 