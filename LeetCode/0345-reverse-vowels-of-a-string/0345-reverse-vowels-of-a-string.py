class Solution:
    def reverseVowels(self, s: str) -> str:
        left = 0
        right = len(s) - 1
        result = list(s)
        s = s.lower()
        VOWELS = ['a', 'e', 'i', 'o', 'u']

        while left < right:

            left_is_vowel = s[left] in VOWELS
            right_is_vowel = s[right] in VOWELS

            if left_is_vowel and right_is_vowel:
                result[left], result[right] = result[right], result[left]
                left += 1
                right -= 1
            elif not left_is_vowel:
                left += 1
            else:
                right -= 1
        
        return "".join(result)
                