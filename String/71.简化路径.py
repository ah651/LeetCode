class Solution:
    def simplifyPath(self, path: str) -> str:
        if len(path) == 0:
            return '' 
        paths = []
        i = 0
        while i<len(path) and i < len(path):
            while i<len(path) and path[i] == '/':
                i += 1 
            lo = i 
            while i<len(path) and path[i] != '/':
                i += 1
            hi = i
            current_path = path[lo:hi]
            if current_path == '.':
                pass 
            elif current_path == '..':
                if len(paths) > 0:
                    paths.pop()
            else:
                if len(current_path) > 0:
                    paths.append(current_path)

        tmp =  '/'.join(paths)
        return '/' + tmp