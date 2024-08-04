class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = ['a','e','i','o','u']

        slide = 0
        
        for c in s[:k]:
            if c in vowels:
                slide += 1

        max_num_vowel = slide
        
        for i in range(0, len(s) - k):
            if s[i] in vowels:
                slide -= 1
            if s[i + k] in vowels:
                slide += 1

            max_num_vowel = max(max_num_vowel, slide)    
    
        return max_num_vowel