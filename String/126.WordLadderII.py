from collections import deque
import string
import copy 

class Solution:
    #BFS
    def findLadders(self, beginWord: str, endWord: str, wordList):
        if len(wordList) < 1:
            return []
        if len(wordList[0]) != len(beginWord) or len(wordList[0]) != len(endWord) or len(endWord) != len(beginWord):
            return []
        if endWord not in wordList:
            return []

        result = []
        bfs_queue = deque()
        bfs_queue.append([beginWord])
        discovered_set = set()
        discovered_set.add(beginWord)
        endFlag = False 
        while not endFlag and len(bfs_queue) != 0:
            current_len = len(bfs_queue)
            current_disvered = set()
            for i in range(current_len):
                path = bfs_queue.popleft()
                word = path[-1]
                neibors = self.get_neibor(word, wordList)
                for neibor in neibors:
                    if neibor not in discovered_set:
                        current_disvered.add(neibor)
                        if neibor == endWord:
                            path.append(neibor)
                            result.append(copy.deepcopy(path))
                            path.pop()
                            endFlag = True 
                        path.append(neibor)
                        bfs_queue.append(copy.deepcopy(path))
                        path.pop()
            discovered_set = discovered_set.union(current_disvered)

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