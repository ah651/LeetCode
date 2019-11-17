class Solution:
    '''
    dp fill tabel has 4 situation
    1. up to down, left to right
    2. up to down, right to left
    3. down to up, right to left
    4. down to up, left to right
    '''

    def longestPalindrome(self, s: str) -> str:
        if len(s) < 2:
            return s

        dp_table = [[True if i==j else False for j in range(len(s))] for i in range(len(s))]
        result = s[0]
        for i in range(len(s)-1, -1, -1):
            for j in range(i+1, len(s)):
                if s[i] == s[j] and (j == i+1 or dp_table[i+1][j-1] == True):
                    dp_table[i][j] = True
                    if j - i + 1 > len(result):
                        result = s[i:j+1]
        return result