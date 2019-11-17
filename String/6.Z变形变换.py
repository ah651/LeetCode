class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if len(s) <= numRows or numRows == 1:
            return s
        
        interval = 2*(numRows-2) + 2
        len_s = len(s)
        num_group = len_s // interval
        remainder = len_s % interval
        result = ''
        #first interval
        for i in range(num_group):
            result += s[i*interval]
        if remainder > 0:
            result += s[interval*num_group]
        
        for inter in range(1, numRows-1):
            for i in range(num_group):
                result += s[i*interval + inter]
                result += s[i*interval + interval - inter]
            if remainder >= inter+1:
                result += s[interval*num_group + inter]
            if remainder >= (interval - inter + 1):
                result += s[interval*num_group + interval - inter]

        #last interval
        for i in range(num_group):
            result += s[i*interval + numRows - 1]
        if remainder >= numRows:
            result += s[num_group*interval + numRows - 1]
        

        return result