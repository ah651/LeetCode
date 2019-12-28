class Solution:
    '''
    Like DP and DFS
    '''
    def longestIncreasingPath(self, matrix) -> int:
        if len(matrix) == 0:
            return 0
        if len(matrix[0]) == 0:
            return 0 
        
        self.len_path = [[0 for j in range(len(matrix[0]))] for i in range(len(matrix))]
        self.result = 1
        self.matrix = matrix
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if self.len_path[i][j] == 0:
                    tmp = self.dfs(i, j)
                    if tmp > self.result:
                        self.result = tmp
        return self.result
    
    def dfs(self, i, j):
        left = 0
        if j-1>=0 and self.matrix[i][j-1] > self.matrix[i][j]:
            if self.len_path[i][j-1] > 0:
                left = self.len_path[i][j-1]
            else:
                left = self.dfs(i, j-1)
        right = 0
        if j+1<len(self.matrix[0]) and self.matrix[i][j+1] > self.matrix[i][j]:
            if self.len_path[i][j+1] > 0:
                right = self.len_path[i][j+1]
            else:
                right = self.dfs(i, j+1)
        up = 0
        if i-1>=0 and self.matrix[i-1][j] > self.matrix[i][j]:
            if self.len_path[i-1][j] > 0:
                up = self.len_path[i-1][j]
            else:
                up = self.dfs(i-1, j)
        down = 0
        if i+1<len(self.matrix) and self.matrix[i+1][j] > self.matrix[i][j]:
            if self.len_path[i+1][j] > 0:
                down = self.len_path[i+1][j]
            else:
                down = self.dfs(i+1, j)
        tmp = 1+max(left, right, up, down)
        self.len_path[i][j] = tmp
        return tmp
