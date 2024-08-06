import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        result = 0

        for num in nums:
            heapq.heappush(heap, -num)

        for _ in range(k):
            result = -heapq.heappop(heap)

        return result