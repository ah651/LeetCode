class Solution:
    '''
    naive dfs solution
    '''
    def removeInvalidParentheses(self, s: str):
        if len(s) == 0:
            return ['']
        remove_left = 0
        remove_right = 0
        for c in s:
            if c == '(':
                remove_left += 1
            elif c == ')':
                if remove_left > 0:
                    remove_left -= 1 
                else:
                    remove_right += 1
        result = []
        self.dfs_remove(s, 0, [], remove_left, remove_right, result)
        # result = set(result)
        if len(result) == 0:
            tmp = ''
            for c in s:
                if c != '(' and c != ')':
                    tmp += c
            return [tmp]
        else:
            return result

    def dfs_remove(self, s, idx, removed, remove_left, remove_right, result):
        if idx >= len(s):
            if remove_left == 0 and remove_right == 0:
                tmp = ''
                for i in range(len(s)):
                    if i not in removed:
                        tmp += s[i]
                cnt = 0
                for c in tmp:  
                    if c == '(':
                        cnt += 1
                    elif c == ')':
                        if cnt <= 0:
                            cnt -= 1
                            break 
                        else:
                            cnt -= 1
                if cnt == 0:
                    result.append(tmp)
        else:                
            if s[idx] == '(' and remove_left > 0:
                cur = idx
                while idx < len(s) and s[idx] == s[cur]:
                    idx += 1
                #don't delete
                self.dfs_remove(s, idx, removed, remove_left, remove_right, result)
                removed.append(cur)
                self.dfs_remove(s, cur+1, removed, remove_left-1, remove_right, result)
                removed.pop()
            elif s[idx] == ')' and remove_right > 0:
                cur = idx
                while idx < len(s) and s[idx] == s[cur]:
                    idx += 1
                self.dfs_remove(s, idx, removed, remove_left, remove_right, result)
                removed.append(cur)
                self.dfs_remove(s, cur+1, removed, remove_left, remove_right-1, result)
                removed.pop()
            else:
                self.dfs_remove(s, idx+1, removed, remove_left, remove_right, result)


        