class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0, right =0, cursor = 0, size = nums.size();
        for(int num : nums) right += num;
        right -= nums[0];
        while(left != right) {
            left += nums[cursor++];
            if(cursor >= size) break;
            right -= nums[cursor];
        }
        if(size == cursor) return -1;
        return cursor;
    }
};