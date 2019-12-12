class Solution:
    def canFinish(self, numCourses: int, prerequisites) -> bool:
        if numCourses <= 1:
            return True 
        if len(prerequisites) <= 1:
            return True 
        
        class Graph:
            def __init__(self, num_nodes, edges):
                self.num_nodes = num_nodes
                self.adj_table = [[] for i in range(num_nodes)]
                for e in edges:
                    self.adj_table[e[1]].append(e[0])
                self.visited = [False for i in range(num_nodes)]
                self.discovered = [False for i in range(num_nodes)]

            def dfs_find_cycle(self, start):
                self.discovered[start] = True 
                result = False
                for end in self.adj_table[start]:
                    if not self.discovered[end]:
                        tmp = self.dfs_find_cycle(end)
                        if tmp:
                            result = True
                            break  
                    elif self.discovered[end] and not self.visited[end]:
                        result = True
                        break  
                    
                self.visited[start] = True 
                return result                  
        
        g = Graph(numCourses, prerequisites)
        for i in range(numCourses):
            if not g.discovered[i]:
                tmp = g.dfs_find_cycle(i)
                if tmp:
                    return False 
        return True 
