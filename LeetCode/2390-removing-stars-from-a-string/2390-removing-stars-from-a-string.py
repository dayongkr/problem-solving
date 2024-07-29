class Solution:
    def rec(self, stack: list, star: int, result:list) -> list:
        if not stack:
            return result
        
        cur = stack.pop()
        
        if cur == '*':
            star += 1
        elif not star:
            result.append(cur)
        else:
            star -= 1

        return self.rec(stack, star, result)

    def removeStars(self, s: str) -> str:
        return "".join(reversed(self.rec(list(s), 0, [])))