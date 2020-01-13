class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if nums == None or len(nums) == 0:
            return -1 
        # find rotate point
        lo, hi = 0, len(nums)-1
        while lo < hi:
            mid = (lo+hi)//2 
            # if nums[mid] > nums[lo] and nums[mid] > nums[hi]:
            if nums[mid] > nums[hi]:
                lo = mid+1 
            # elif nums[mid] < nums[lo] and nums[mid] < nums[hi]:
            #elif nums[mid] < nums[hi]:
            else:
                hi = mid
        rotate_point = lo 
        lo, hi = 0, len(nums)-1
        while lo <= hi:
            mid = (lo + hi) // 2
            real_mid = (mid +rotate_point) % len(nums)
            if nums[real_mid] > target:
                hi = mid-1 
            elif nums[real_mid] < target:
                lo = mid+1 
            else:
                return real_mid 
        return -1