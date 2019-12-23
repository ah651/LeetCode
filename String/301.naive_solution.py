class Solution:
    '''
    naive dfs solution
    '''
    def removeInvalidParentheses(self, s: str):
        if len(s) == 0:
            return [""]
        self.result = set()
        self.removed = float('inf')
        self.s = s
        self.dfs(0, [], 0, 0, 0)
        return self.result
    
    def __init__(self):
        super().__init__()
        self.result = set()
        self.removed = float('inf')
        self.s = ''

    def dfs(self, idx, tmp_st, left, right, removed):
        if idx >= len(self.s):
            if left == right and removed <= self.removed:
                if removed < self.removed:
                    self.removed = removed
                    self.result = set()
                tmp = ''.join(tmp_st)
                self.result.add(tmp)
            return 
        
        if self.s[idx] != '(' and self.s[idx] != ')':
            tmp_st.append(self.s[idx])
            self.dfs(idx+1, tmp_st, left, right, removed)
            tmp_st.pop()
        else:
            #remove
            self.dfs(idx+1, tmp_st, left, right, removed+1)
            #insert
            tmp_st.append(self.s[idx])
            if self.s[idx] == '(':
                self.dfs(idx+1, tmp_st, left+1, right, removed)
            elif right+1 <= left:
                self.dfs(idx+1, tmp_st, left, right+1, removed)
            #pop is not must in this problem, but reset status is a good habit
            tmp_st.pop()

        