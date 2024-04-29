class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int N = nums.size();
        if (N == 1)
            return;
        int p1 = 0, p2 = 1;
        while (p1 < N && p2 < N) {
            if (nums[p1] == 0) {
                if (p2 <= p1)
                    p2 = p1 + 1;
                else if (nums[p2] != 0)
                    swap(nums[p1], nums[p2]);
            }
            if (nums[p1] != 0)
                p1++;
            if (nums[p2] == 0)
                p2++;
        }
    }
};