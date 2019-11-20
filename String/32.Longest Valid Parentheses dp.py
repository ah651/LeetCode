class Solution:
    #dp, down to up, left to right
    #this kind of longest string, use dp commonly only need one dim dp_table
    #common dp_table[i] define: longgest substr end with s[i] 

    def longestValidParentheses(self, s: str) -> int:
        if len(s) <= 1:
            return 0
        result = 0
        dp_table = [0 for i in range(len(s))]
        if s[0:2] == '()':
            dp_table[1] = 2
            result = 2
        for i in range(2, len(s)): 
            if s[i] == ')':
                #different situation, different kinds of classify
                #case 1: (()())()
                if s[i-1] == '(':
                    dp_table[i] = dp_table[i-2] + 2
                #case 2: () (()())
                elif  i-dp_table[i-1]-1 >=0 and s[i-dp_table[i-1]-1] == '(':
                    if i-dp_table[i-1]-2 >= 0:
                        dp_table[i] = dp_table[i-1] + 2 + dp_table[i-dp_table[i-1]-2]
                    else:
                        dp_table[i] = dp_table[i-1] + 2


                if dp_table[i] > result:
                    result = dp_table[i]

        return result 
