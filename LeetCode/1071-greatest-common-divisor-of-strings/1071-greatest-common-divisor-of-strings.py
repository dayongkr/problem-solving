from math import gcd

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        GCD = gcd(len(str1), len(str2))
        prefix = str1[:GCD]
        
        for i in range(0, len(str1), GCD):
            if str1[i : i + GCD] != prefix:
                return ""
        for i in range(0, len(str2), gcd):
            if str2[i : i + gcd] != prefix:
                return ""

        return prefix
