class Solution:
    def searchRange(self, nums, target: int):
        if nums == None or len(nums) == 0:
            return [-1, -1]
        lo, hi = 0, len(nums)-1 
        while lo <= hi:
            mid = (lo + hi) // 2
            if nums[mid] < target:
                lo = mid + 1 
            else:
                hi = mid - 1
        if lo >= len(nums) or nums[lo] != target:
            return [-1, -1]
        else:
            tmp = lo 
            lo, hi = 0, len(nums)-1 
            while lo <= hi:
                mid = (lo + hi) // 2
                if nums[mid] <= target:
                    lo = mid + 1 
                else:
                    hi = mid - 1 
            return [tmp, lo-1]