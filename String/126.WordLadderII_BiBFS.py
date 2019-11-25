from collections import deque
import string
import copy 

class Solution:
    #Bi-BFS
    def findLadders(self, beginWord: str, endWord: str, wordList):
        if len(wordList) < 1:
            return []
        if len(wordList[0]) != len(beginWord) or len(wordList[0]) != len(endWord) or len(endWord) != len(beginWord):
            return []
        if endWord not in wordList:
            return []

        result = []
        q1 = [[beginWord]]
        q2 = [[endWord]]
        discoverd1 = set([beginWord])
        discoverd2 = set([endWord])
        endFlag = False
        direct = True 
        while not endFlag and len(q1) > 0:
            current_len = len(q1)
            current_disvocerd = set()
            current_path = []
            for i in range(current_len):
                path = q1[i]
                word = path[-1]
                neibors = self.get_neibor(word, wordList)
                for neibor in neibors:
                    if neibor in discoverd1:
                        continue 
                    if neibor in discoverd2:
                        endFlag = True
                        if direct:
                            for path2 in q2:
                                if path2[-1] == neibor:

                                    tmp = copy.deepcopy(path2)
                                    tmp.reverse()
                                    result.append(copy.deepcopy(path + tmp))
                        else:
                            for path2 in q2:
                                if path2[-1] == neibor:
                                    tmp = copy.deepcopy(path)
                                    tmp.reverse()
                                    result.append(copy.deepcopy(path2 + tmp))
                    else:
                        current_disvocerd.add(neibor)
                        path.append(neibor)
                        current_path.append(copy.deepcopy(path))
                        path.pop()
            discoverd1 = discoverd1.union(current_disvocerd)

            if len(current_path) > len(q2):
                q1 = q2
                q2 = current_path 
                tmp = discoverd1
                discoverd1 = discoverd2 
                discoverd2 = tmp 
                direct = not direct
            else:
                q1 = current_path
            
        return result 


    
    def get_neibor(self, word, wordList):
        result = []
        wordSet = set(wordList)
        for i in range(len(word)):
            current_char = word[i]
            for c in string.ascii_lowercase:
                if c == current_char:
                    continue
                word = word[:i] + c + word[i+1:]
                if word in wordSet:
                    result.append(word)
            word = word[:i] + current_char + word[i+1:]
            
        
        return result