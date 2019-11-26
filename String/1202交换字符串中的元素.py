class Solution:
    # union find to solve connected graph problem
    def smallestStringWithSwaps(self, s: str, pairs) -> str:
        if len(pairs) == 0:
            return s 
        if len(s) == 0:
            return s
        uf = self.uf(len(s))
        for pair in pairs:
            uf.union(pair[0], pair[1])
        groupChar = {}
        for i in range(len(s)):
            r = uf.onlyFind(i)
            if r not in groupChar:
                groupChar[r] = [s[i]]
            else:
                groupChar[r].append(s[i])
        for group in groupChar:
            groupChar[group].sort(reverse = True)
        result = []
        for i in range(len(s)):
            r = uf.onlyFind(i)
            result.append(groupChar[r].pop())
        return "".join(result)


    class uf:
        def __init__(self, n):
            self.pre = list(range(n))
        def find(self, x):
            # find and return root
            r = x
            while self.pre[r] != r:
                r = self.pre[r]
            # path compress
            y = x
            while y != r:
                tmp = self.pre[y]
                self.pre[y] = r  
                y = tmp           
            return r 

        def onlyFind(self, x):
            # find and return root
            r = x
            while self.pre[r] != r:
                r = self.pre[r]
            # path compress
            return r 

        def union(self, x, y):
            rx = self.find(x)
            ry = self.find(y)
            self.pre[rx] = ry