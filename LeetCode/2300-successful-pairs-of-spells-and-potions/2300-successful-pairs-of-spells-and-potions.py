from bisect import bisect_left

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        result = []
        potions_len = len(potions)

        for spell in spells:
            pairs = bisect_left(potions, success, key=lambda x: x * spell)
            result.append(potions_len - pairs)
        
        return result