class Solution:
    def generateParenthesis(self, n: int):
        if n == 0:
            return []
        if n == 1:
            return ['()']
        result = []
        self.allParenthesis(n, n, result, '')
        return result
    def allParenthesis(self, leftCnt, rightCnt, results, tmpParenthe):
        if leftCnt == 0:
            while rightCnt > 0:
                rightCnt -= 1
                tmpParenthe += ')'
            results.append(tmpParenthe)
        else:
            if leftCnt == rightCnt:
                self.allParenthesis(leftCnt-1, rightCnt, results, tmpParenthe+'(')
            else:
                self.allParenthesis(leftCnt-1, rightCnt, results, tmpParenthe+'(')
                self.allParenthesis(leftCnt, rightCnt-1, results, tmpParenthe+')')
