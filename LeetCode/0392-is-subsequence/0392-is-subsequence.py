class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        t_ptr = 0
        t_len = len(t)

        for char in s:
            while t_ptr < t_len and char != t[t_ptr]:
                t_ptr += 1
            
            if t_ptr == t_len:
                return False
            
        return True