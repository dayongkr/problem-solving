class Solution:
    def reverseWords(self, s: str) -> str:
        reversed_list = list(reversed(s.strip().split()))
        return " ".join(reversed_list)