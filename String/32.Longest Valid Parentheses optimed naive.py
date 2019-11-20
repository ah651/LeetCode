class Solution:
    #dp, down to up, left to right
    #this kind of longest string, use dp commonly only need one dim dp_table
    #common dp_table[i] define: longgest substr end with s[i] 

    #optimed naive solution
    def longestValidParentheses(self, s: str) -> int:
        if len(s) <= 1:
            return 0
        result = 0
        for i in range(len(s)-1):
            if s[i] == ')':
                continue 
            cnt = 1
            for j in range(i+1, len(s)):
                if s[j] == '(':
                    cnt += 1
                else:
                    cnt -= 1
                if cnt < 0:
                    break             
                elif cnt == 0:
                    if (j - i + 1) > result:
                        result = (j-i+1)
            
        return result 