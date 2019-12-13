class Solution:
    def findOrder(self, numCourses: int, prerequisites):
        if numCourses <= 1:
            return list(range(numCourses)) 
        if len(prerequisites) == 0:
            return list(range(numCourses)) 
        
        class Graph:
            def __init__(self, num_nodes, edges):
                self.num_nodes = num_nodes
                self.node_indegree = [0 for i in range(num_nodes)]
                self.adj_table = [[] for i in range(num_nodes)]
                for e in edges:
                    self.adj_table[e[1]].append(e[0])
                    self.node_indegree[e[0]] += 1

            def toplogic(self):
                result = []
                zero_queue = []
                for i in range(self.num_nodes):
                    if self.node_indegree[i] == 0:
                        zero_queue.append(i)
                while len(zero_queue) != 0:
                    tmp = zero_queue.pop()
                    result.append(tmp)
                    for end in self.adj_table[tmp]:
                        self.node_indegree[end] -= 1
                        if self.node_indegree[end] == 0:
                            zero_queue.append(end)
                    
                if len(result) < self.num_nodes:
                    return []
                else:
                    return result

        g = Graph(numCourses, prerequisites)
        return g.toplogic()