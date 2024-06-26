class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, n = nums.size(), MAX = 0;
        for (int i = 0; i < k; i++)
            sum += nums[i];
        MAX = sum;
        for (int i = 1; i <= n - k; i++) {
            sum -= nums[i - 1];
            sum += nums[i + k - 1];
            MAX = max(sum, MAX);
        }
        return (double) MAX / k;
    }
};