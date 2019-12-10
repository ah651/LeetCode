class Solution:
    def wiggleMaxLength(self, nums) -> int:
        if len(nums) <= 1:
            return len(nums)

        cnt = 1
        up_flag = True 
        
        i = 1
        add_flag = False
        while i < len(nums):
            if up_flag:
                if nums[i] > nums[i-1]:
                    i += 1
                    add_flag = True 
                elif nums[i] == nums[i-1]:
                    i += 1
                else:
                    up_flag = not up_flag
                    if add_flag:
                        cnt += 1
                        add_flag = False     
            else:
                if nums[i] < nums[i-1]:
                    i += 1
                    add_flag = True
                elif nums[i] == nums[i-1]:
                    i += 1
                else:
                    up_flag = not up_flag
                    if add_flag:
                        cnt += 1
                        add_flag = False
                
        if add_flag:
            cnt += 1

        return cnt              