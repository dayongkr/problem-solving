from collections import Counter

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        occurences = set()
        counts = Counter(arr).values()

        for count in counts:
            if count in occurences:
                return False
            occurences.add(count)

        return True