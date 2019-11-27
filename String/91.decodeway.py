class Solution:
    #dfs may not be the best way, if dfs over time, think about dp
    def numDecodings(self, s: str) -> int:
        if len(s) < 1:
            return 0
        if s[0] == '0':
            return 0
        if len(s) == 1:
            return 1

        dp_table = [0 for i in s]
        dp_table[len(s)-1] = 0 if s[-1] == '0' else 1
        if s[-2] == '0':
            dp_table[-2] = 0
        else:
            dp_table[-2] = dp_table[-1]
        if s[-2] == '1' or (s[-2] == '2' and s[-1] in '0123456'):
            dp_table[-2] += 1
        for i in range(len(s)-3, -1, -1):
            if s[i] == '0':
                dp_table[i] = 0
            else:
                dp_table[i] = dp_table[i+1]
            if s[i] == '1' or (s[i] == '2' and s[i+1] in '0123456'):
                dp_table[i] += dp_table[i+2]
            
        return dp_table[0]

