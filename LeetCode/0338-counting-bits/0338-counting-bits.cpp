class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        int power = 1;
        result.push_back(0);
        if (n >= 1)
            result.push_back(1);
        for (int i = 2; i <= n; i++) {
            int temp = i % power;
            if (temp == 0) {
                result.push_back(1);
                power <<= 1;
            } else {
                result.push_back(result[temp] + 1);
            }
        }
        return result;
    }
};