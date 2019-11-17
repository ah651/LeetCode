class Solution:
    def longestCommonPrefix(self, strs) -> str:
        if len(strs) == 0:
            return ''
        if len(strs) == 1:
            return strs[0]
        result = ''
        i = 0
        try:
            while True:
                tmpchar = strs[0][i]
                for s in strs:
                    if s[i] != tmpchar:
                        raise Exception
                result += tmpchar
                i += 1
        except:
            return result