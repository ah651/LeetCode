class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if len(word1) == 0:
            return len(word2)
        if len(word2) == 0:
            return len(word1)
        max_dis = len(word1) + len(word2)
        dp_table = [[max_dis for j in range(len(word1)+1)] for i in range(len(word2)+1)]
        for i in range(len(word1)+1):
            dp_table[0][i] = i 
        for j in range(len(word2)+1):
            dp_table[j][0] = j    
        for i in range(1, len(word2)+1):
            for j in range(1, len(word1)+1):
                if word1[j-1] == word2[i-1]:
                    dp_table[i][j] = dp_table[i-1][j-1]
                else:
                    dp_table[i][j] = 1+dp_table[i-1][j-1]
                dp_table[i][j] = min(dp_table[i-1][j]+1, dp_table[i][j-1]+1, dp_table[i][j])

        return dp_table[len(word2)][len(word1)]