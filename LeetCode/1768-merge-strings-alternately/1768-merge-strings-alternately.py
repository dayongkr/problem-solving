class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        word1_len = len(word1)
        word2_len = len(word2)
        max_length = max(word1_len, word2_len)
        result = ""
        for i in range(max_length):
            if(i < word1_len):
                result += word1[i]
            if(i < word2_len):
                result += word2[i]
        return result
        