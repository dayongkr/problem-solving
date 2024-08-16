from math import ceil

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right = 1, int(1e9)
        result = int(1e9)

        while left <= right:
            k = (right - left) // 2 + left
            time = 0

            for pile in piles:
                time += ceil(pile / k)
            
            if time <= h:
                result = min(result, k)
                right = k - 1
            else:
                left = k + 1
        
        return result