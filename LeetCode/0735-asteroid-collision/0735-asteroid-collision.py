class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []

        for cur in asteroids:
            curSize = abs(cur)
            haveToAdd = True

            while stack and cur < 0:
                top = stack.pop()
                topSize = abs(top)

                if top > 0:
                    if topSize > curSize:
                        cur = top
                        curSize = topSize
                    elif topSize == curSize:
                        haveToAdd = False
                        break
                else:
                    stack.append(top)
                    break
            
                if not haveToAdd:
                    break

            if haveToAdd:
                stack.append(cur)
                
        return stack