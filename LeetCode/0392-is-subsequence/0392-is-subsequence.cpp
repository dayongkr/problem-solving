class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_length = s.length(), t_length = t.length(), p1 = 0, p2 = 0;
        if (s_length > t_length)
            return false;
        while (p1 < s_length && p2 < t_length) {
            if (s[p1] == t[p2])
                p1++;
            p2++;
        }
        if (p1 == s_length)
            return true;
        return false;
    }
};