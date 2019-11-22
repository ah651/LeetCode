class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(a) == 0:
            return b 
        if len(b) == 0:
            return a 
        ia, ib = len(a)-1, len(b)-1
        tmp_sum = 0
        result = ''
        #treat a and b has same length
        while ia >= 0 or ib >= 0:
            if ia < 0:
                a_ia = '0'
            else:
                a_ia = a[ia]
                ia -= 1
            if ib < 0:
                b_ib = '0'
            else:
                b_ib = b[ib]
                ib -= 1        
            if a_ia == '1' and b_ib == '1' and tmp_sum == 1:
                tmp_sum = 1
                result = '1' + result
            elif a_ia == '1' and b_ib == '1' and tmp_sum == 0:
                tmp_sum = 1
                result = '0' + result
            elif a_ia == '1' and b_ib == '0' and tmp_sum == 0:
                tmp_sum = 0
                result = '1' + result
            elif a_ia == '1' and b_ib == '0' and tmp_sum == 1:
                tmp_sum = 1
                result = '0' + result
            elif a_ia == '0' and b_ib == '1' and tmp_sum == 1:
                tmp_sum = 1
                result = '0' + result
            elif a_ia == '0' and b_ib == '1' and tmp_sum == 0:
                tmp_sum = 0
                result = '1' + result
            elif a_ia == '0' and b_ib == '0' and tmp_sum == 1:
                tmp_sum = 0
                result = '1' + result
            else:
                tmp_sum = 0
                result = '0' + result
        if tmp_sum == 1:
            result = '1' + result

        return result
