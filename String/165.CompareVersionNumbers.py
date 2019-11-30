class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        if len(version1) == 0 and len(version2) == 0:
            return 0
        if len(version1) == 0:
            return -1 
        if len(version2) == 0:
            return 1

        v1 = version1.split('.')
        v2 = version2.split('.')
        i, j = 0, 0
        while i < len(v1) or j < len(v2):
            a = int(v1[i]) if i < len(v1) else 0
            b = int(v2[j]) if j < len(v2) else 0
            if a < b:
                return -1 
            if a > b:
                return 1
            i += 1
            j += 1
        
        return 0