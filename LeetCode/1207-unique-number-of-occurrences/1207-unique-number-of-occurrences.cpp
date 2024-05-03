class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int counts[2001] =
            {
                0,
            },
            ouccurences[1001] = {
                0,
            };
        for (int num : arr) {
            num += 1000;
            ++counts[num];
        }
        for (int i = 0; i <= 2000; i++) {
            int count = counts[i];
            if (count == 0)
                continue;
            if (ouccurences[count])
                return false;
            ouccurences[count] = 1;
        }
        return true;
    }
};