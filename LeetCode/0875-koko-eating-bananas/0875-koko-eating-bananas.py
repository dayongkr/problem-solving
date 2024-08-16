from math import ceil

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right = 1, max(piles)

        while left <= right:
            k = (right - left) // 2 + left
            time = sum(ceil(pile / k) for pile in piles)

            if time <= h:
                right = k - 1
            else:
                left = k + 1
        
        return left