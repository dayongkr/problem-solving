class Solution:
    def removeStars(self, s: str) -> str:
        result = []

        for c in s:
            if c == '*':
                result.pop()
            else:
                result.append(c)

        return "".join(result)