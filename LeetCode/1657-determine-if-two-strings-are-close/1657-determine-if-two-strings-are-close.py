class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        frequency_word1 = Counter(word1)
        frequency_word2 = Counter(word2)

        sorted_word1 = sorted(frequency_word1.values())
        sorted_word2 = sorted(frequency_word2.values())

        return sorted_word1 == sorted_word2 and frequency_word1.keys() == frequency_word2.keys()