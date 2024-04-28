class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0, p2 = 0, N = word1.length(), M = word2.length();
        string result = "";
        while (p1 < N && p2 < M) {
            result += word1[p1++];
            result += word2[p2++];
        }
        if (p1 < N)
            result += word1.substr(p1);
        if (p2 < M)
            result += word2.substr(p2);
        return result;
    }
};