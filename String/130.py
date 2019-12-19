class Solution:
    def solve(self, board) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if len(board) == 0 or len(board[0]) == 0:
            return 

        remark = [[False for j in range(len(board[0]))] for i in range(len(board))]
        for i in range(len(board[0])):
            if board[0][i] == 'O' and remark[0][i] == False:
                self.dfs(0, i, board, remark)
            if board[-1][i] == 'O' and remark[-1][i] == False:
                self.dfs(len(board)-1, i, board, remark)
        for j in range(1, len(board)):
            if board[j][0] == 'O' and remark[j][0] == False:
                self.dfs(j, 0, board, remark)
            if board[j][len(board[0])-1] == 'O' and remark[j][len(board[0])-1] == False:
                self.dfs(j, len(board[0])-1, board, remark)

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'O' and not remark[i][j]:
                    board[i][j] = 'X'

    def dfs(self, r, c, board, remark):
        remark[r][c] = True 
        if c-1>=0 and board[r][c-1] == 'O' and remark[r][c-1] == False:
            self.dfs(r, c-1, board, remark)
        if c+1<len(board[0]) and board[r][c+1] == 'O' and remark[r][c+1] == False:
            self.dfs(r, c+1, board, remark)
        if r-1>=0 and board[r-1][c] == 'O' and remark[r-1][c] == False:
            self.dfs(r-1, c, board, remark)
        if r+1<len(board) and board[r+1][c] == 'O' and remark[r+1][c] == False:
            self.dfs(r+1, c, board, remark)
        