class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        result = ""

        for c in s:
            if c != ']':
                stack.append(c)
            else:
                temp = []
                repeated = 0

                while stack:
                    top = stack.pop()

                    if top != '[':
                        temp.append(top)
                    else:
                        break

                point = 1
                while stack:
                    top = stack.pop()
                    if '0' <= top <= '9':
                        repeated += int(top) * point
                        point *= 10
                    else:
                        stack.append(top)
                        break

                stack.append(("".join(reversed(temp)) * repeated))

        
        return "".join(stack)

                