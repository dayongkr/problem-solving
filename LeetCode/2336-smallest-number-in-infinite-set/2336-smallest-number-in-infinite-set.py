import heapq

class SmallestInfiniteSet:

    def __init__(self):
        self.heap = list(range(1, 1001))
        heapq.heapify(self.heap)

    def popSmallest(self) -> int:
        smallest = heapq.heappop(self.heap)
        while self.heap and smallest == self.heap[0]:
            heapq.heappop(self.heap)
        return smallest
        

    def addBack(self, num: int) -> None:
        heapq.heappush(self.heap, num)
        


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)