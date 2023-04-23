int XORSum(const int *nums, int s, int e, int term) {
    if (s > e) return term;
    return XORSum(nums, s + 1, e, term) + XORSum(nums, s + 1, e, term ^ nums[s]);
}

int subsetXORSum(int *nums, int numsSize) {
    return XORSum(nums, 0, numsSize - 1, 0);
}