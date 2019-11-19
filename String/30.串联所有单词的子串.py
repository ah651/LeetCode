class Solution:
    def findSubstring(self, s: str, words):
        if len(words) == 0:
            return []
        if words[0] == '':
            return []
        if len(s) < len(words)*len(words[0]):
            return []

        #generate a map to avoid order of words
        words_map = {}
        match_map = {}
        words_set = set(words)
        for word in words:
            if word not in words_map:
                words_map[word] = 1
                match_map[word] = 0
            else:
                words_map[word] += 1
        word_len = len(words[0])
        word_num = len(words)
        result = []
        for i in range(0, len(s)-word_num*word_len+1):
            break_flag = False
            for word in words_set:
                match_map[word] = 0
            for j in range(word_num):
                if s[i+j*word_len:i+j*word_len+word_len] not in words_set:
                    break_flag = True 
                    break 
                match_map[s[i+j*word_len:i+j*word_len+word_len]] += 1
                if match_map[s[i+j*word_len:i+j*word_len+word_len]] > words_map[s[i+j*word_len:i+j*word_len+word_len]]:
                    break_flag = True
                    break 
            #check result
            if not break_flag:
                result.append(i)
        
        return result 