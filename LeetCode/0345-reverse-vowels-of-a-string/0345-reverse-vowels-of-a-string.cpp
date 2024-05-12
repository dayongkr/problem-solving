class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' ||
               c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            bool lVowel = isVowel(s[l]), rVowel = isVowel(s[r]);
            if (!lVowel)
                l++;
            if (!rVowel)
                r--;
            if(lVowel && rVowel) swap(s[l++],s[r--]);
        }
        return s;
    }
};