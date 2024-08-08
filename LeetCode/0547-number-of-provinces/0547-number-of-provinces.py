from collections import deque


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        visited = [False for _ in range(n)]
        provinces = 0

        for i in range(n):
            if visited[i]:
                continue

            queue = deque()

            queue.append(i)
            visited[i] = True

            while queue:
                top = queue.popleft()
                for j in range(n):
                    if not visited[j] and isConnected[top][j]:
                        queue.append(j)
                        visited[j] = True

            provinces += 1

        return provinces
