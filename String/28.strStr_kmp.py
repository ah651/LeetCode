class Solution:
    # find a substr should directly use naive solution
    # if overtime, use KMP
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == '':
            return 0 
        if len(haystack) < len(needle):
            return -1
        ne = self.nextTable(needle)
        print(ne)
        i, j = 0, 0
        while i < len(haystack) and j < len(needle):
            if j == -1 or haystack[i] == needle[j]:
                i += 1
                j += 1
            else:
                j = ne[j]
        if j == len(needle):
            return i - j
        return -1


    def nextTable(self, p : str):
        ne = [-1 for i in range(len(p))]
        i, j = 0, -1
        while i < len(p)-1:
            if j == -1 or p[i] == p[j]:
                i += 1
                j += 1
                ne[i] = j 
            else:
                j = ne[j]
        return ne
