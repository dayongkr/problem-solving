def solution(nums):
    half_N = len(nums) / 2
    unique_N = len(set(nums))

    return unique_N if unique_N < half_N else half_N