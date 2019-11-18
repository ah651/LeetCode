class Solution:
    def myAtoi(self, s: str) -> int:
        if len(s) == 0:
            return 0
        i = 0
        while i < len(s) and s[i] == ' ':
            i += 1
        s = s[i:]
        digital = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
        sign = {'+', '-'}
        if len(s) == 0 or (s[0] not in digital and s[0] not in sign):
            return 0 
        negtive = False
        if s[0] in sign:
            if s[0] == '-':
                negtive = True
            s = s[1:]
        if len(s) == 0 or s[0] not in digital:
            return 0
        result = 0
        i = 0
        while i < len(s) and s[i] in digital:
            result *= 10
            result += int(s[i])
            i += 1
        if negtive:
            result = -result
            if result <= -(2**31):
                result = -(2**31)
            return result 
        if result >= 2**31 -1:
            result = 2**31 -1
        return result 