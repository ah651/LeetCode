class Solution:
    # find a substr should directly use naive solution
    # if overtime, use KMP
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == '':
            return 0 
        if len(haystack) < len(needle):
            return -1
        result = -1 
        for i in range(len(haystack)-len(needle)+1):
            for j in range(len(needle)):
                if haystack[i+j] != needle[j]:
                    break
                if j == len(needle) - 1:
                    return i

        return result

    # def nextTable(p : str):
    #     ne = [-1 for i in range(len(p))]

