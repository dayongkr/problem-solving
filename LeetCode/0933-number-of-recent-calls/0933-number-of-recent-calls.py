from collections import deque

class RecentCounter:

    def __init__(self):
        self.queue = deque()

    def ping(self, t: int) -> int:
        self.queue.append(t)
        limit = t - 3000

        while self.queue[0] < limit:
            self.queue.popleft()

        return len(self.queue)