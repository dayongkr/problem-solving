class Solution:
    def gcd(self, a: int, b: int) -> int:
        if b == 0:
            return a
        else :
            return gcd(b, a % b)

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        gcd = self.gcd(len(str1), len(str2))
        prefix = str1[:gcd]
        print(gcd)
        for i in range(0, len(str1), gcd):
            if str1[i : i + gcd] != prefix:
                return ""
        for i in range(0, len(str2), gcd):
            if str2[i : i + gcd] != prefix:
                return ""

        return prefix
