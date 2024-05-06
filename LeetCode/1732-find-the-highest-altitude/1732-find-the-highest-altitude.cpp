class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result =0, sum = 0;
        for(int num: gain) {
            sum += num;
            result = max(result, sum);
        }
        return result;
    }
};