class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        opens = 1
        n = len(rooms)
        visited = [False for _ in range(n)]
        visited[0] = True
        stack = [0]

        while stack:
            top = stack.pop()
            keys = rooms[top]

            for key in keys:
                if not visited[key]:
                    opens += 1
                    stack.append(key)
                    visited[key] = True

        return opens == n