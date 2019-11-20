class Solution:
    #dp, down to up, left to right
    def longestValidParentheses(self, s: str) -> int:
        if len(s) <= 1:
            return 0
        len_s = len(s)
        dp_table = [[0 for j in range(len_s)] for i in range(len_s)]
        result = 0
        for i in range(len_s-2, -1, -1):
            for j in range(i+1, len_s):
                #(valid)
                if (j-i == 1 or dp_table[i+1][j-1] == 1 )and s[i] == '(' and s[j] == ')':
                    dp_table[i][j] = 1
                    if result < (j-i+1):
                        result = j-i+1
                #()()
                elif s[i] == '(' and s[j] == ')':
                    for k in range(i+1, j):
                        if dp_table[i][k] == 1 and dp_table[k+1][j] == 1:
                            dp_table[i][j] = 1
                            if result < (j-i+1):
                                result = j-i+1
                            break
        
        return result 