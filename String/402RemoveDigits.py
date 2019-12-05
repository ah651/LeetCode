class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if k == 0:
            return num 
        if len(num) <= k:
            return '0'

        cnt = 0
        stack_index = 0
        while cnt < k:
            cnt += 1
            while stack_index < len(num)-1 and num[stack_index] <= num[stack_index+1]: 
                stack_index += 1
            if stack_index == len(num)-1:
                num = num[:stack_index]
            else:
                num = num[:stack_index] + num[stack_index+1:]
            stack_index -= 1
            if stack_index == -1:
                i = 0
                while i < len(num) and num[i] == '0':
                    i += 1
                if i == len(num):
                    return '0'
                else:
                    num = num[i:]
                stack_index = 0
        return num