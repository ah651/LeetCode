class Solution:
    def reversePairs(self, nums) -> int:
        if len(nums) <= 1:
            return 0 
        return self.recursive_sort(nums, 0, len(nums)-1)

    def recursive_sort(self, nums, lo, hi):
        if lo == hi:
            return 0
        else:
            mid = (lo + hi) // 2
            left = self.recursive_sort(nums, lo, mid)
            right = self.recursive_sort(nums, mid+1, hi)

            cnt = 0 
            pl, pr = lo, mid+1 
            while pl <= mid and pr <= hi:
                if nums[pl] > 2 * nums[pr]:
                    cnt += (mid - pl + 1)
                    pr += 1
                else:
                    pl += 1 
            tmp_arr = [0 for i in range(hi-lo+1)]
            pl, pr = lo, mid+1 
            pt = 0 
            while pl <= mid and pr <= hi:
                if nums[pl] <= nums[pr]:
                    tmp_arr[pt] = nums[pl]
                    pl += 1 
                else:
                    tmp_arr[pt] = nums[pr]
                    pr += 1 
                pt += 1
            while pl <= mid:
                tmp_arr[pt] = nums[pl]
                pl += 1 
                pt += 1 
            while pr <= hi:
                tmp_arr[pt] = nums[pr] 
                pr += 1 
                pt += 1 
            nums[lo:hi+1] = tmp_arr
            return cnt+left+right 