class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        if n == 0:
            return ''
        num = 1
        count2int = {1:'1', 2:'2', 3:'3', 4:'4', 5:'5', 6:'6', 7:'7', 8:'8', 9:'9'}
        current = ''
        last = '1'
        while num < n:
            i = 0
            current = ''
            while i < len(last):
                current_char = last[i]
                char_count = 0
                while i < len(last) and last[i] == current_char:
                    char_count += 1
                    i += 1
                current += (count2int[char_count] + current_char)                
            num += 1
            last = current

        return last 