class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        first = second = 2e31 - 1

        for num in nums:
            if num < first:
                first = num
            elif first < num < second:
                second = num
            elif first < second < num:
                return True           
        
        return False
