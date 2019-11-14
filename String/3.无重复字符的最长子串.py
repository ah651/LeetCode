class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # substring, subarray think about slide window first!
        if len(s) <= 1:
            return len(s)
        result = 1
        lo = 0
        hi = 0
        posOfChar = {}
        while hi < len(s):
            if s[hi] in posOfChar and posOfChar[s[hi]] >= lo:
                lo = posOfChar[s[hi]] + 1
            posOfChar[s[hi]] = hi
            
            if result < (hi - lo + 1):
                result = hi - lo + 1

            hi += 1
        return result