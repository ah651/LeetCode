class Solution:
    def numIslands(self, grid) -> int:
        if len(grid) == 0:
            return 0 
        if len(grid[0]) == 0:
            return 0 

        class union_find:
            def __init__(self, m, n):
                super().__init__()
                self.parents = [i for i in range(m*n)]
                self.count = 0 

            def find(self, pos):
                # find root
                origin = pos
                while self.parents[pos] != pos:
                    pos = self.parents[pos]
                root = pos 
                #compress path
                pos = origin
                while self.parents[pos] != root:
                    pos1 = self.parents[pos]
                    self.parents[pos] = root 
                    pos = pos1
                return root 
            
            def union(self, a, b):
                root_a = self.find(a)
                root_b = self.find(b)
                if root_a != root_b:
                    self.count -= 1
                    if root_a < root_b:
                        self.parents[root_b] = root_a
                    else:
                        self.parents[root_a] = root_b
        n = len(grid[0])
        u = union_find(len(grid), len(grid[0]))
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    u.count += 1
                    if j+1 < len(grid[0]) and grid[i][j+1] == '1':
                        u.union((i*n+j), (i*n+j+1))
                    if i+1 < len(grid) and grid[i+1][j] == '1':
                        u.union((i*n+j), ((i+1)*n+j))
        
        return u.count


                


