class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int flowerbed_size = flowerbed.size();
        for (int i = 0; i < flowerbed_size; i++) {
            if (flowerbed[i])
                continue;
            int left = i - 1, right = i + 1;
            if (left < 0)
                ++left;
            if (right >= flowerbed_size)
                --right;
            if (flowerbed[left] == 0 && flowerbed[right] == 0) {
                --n;
                flowerbed[i] = 1;
            }
            if (n <= 0)
                return true;
        }
        if (n <= 0)
            return true;
        return false;
    }
};