class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int s1 = str1.length(), s2 = str2.length(), gcd = __gcd(s1, s2);
        string prefix = str1.substr(0, gcd);
        for (int i = 0; i < s2; i += gcd) {
            if (str2.substr(i, gcd) != prefix)
                return "";
        }
        for (int i = gcd; i < s1; i += gcd) {
            if (str1.substr(i, gcd) != prefix)
                return "";
        }
        return prefix;
    }
};