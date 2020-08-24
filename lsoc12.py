import random 

class Solution:
    def exist(self, board, word: str) -> bool:
        if len(word) == 0:
            return True 
        if len(board) == 0 or len(board[0]) == 0:
            return False 
        valid_path = {} 
        for w in word:
            if w in valid_path:
                valid_path[w] += 1 
            else:
                valid_path[w] = 1 
        self.valid_path = valid_path 

        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        self.directions = directions

        self.total_cnt = len(word) 

        for i in range(len(board)):
            for j in range(len(board[0])):
                if word[0] == board[i][j]:
                    tmp = self.dfs(board, i, j, 0, set(), 0, word)
                    if tmp:
                        return True 
        return False 
        
    def dfs(self, board, row, col, valid_cnt, visited, pos, word):
        valid_cnt += 1 
        visited.add((row, col)) 
        if valid_cnt == self.total_cnt:
            return True

        pos = pos + 1 
        for dx, dy in self.directions:
            x = row + dx 
            y = col + dy 
            if x >= 0 and x < len(board) and y >= 0 and y < len(board[0]) and (x,y) not in visited and board[x][y] == word[pos]:
                tmp = self.dfs(board, x, y, valid_cnt, visited, pos, word)
                if tmp:
                    return True 

        valid_cnt -= 1 
        visited.remove((row, col))

        return False 


 
