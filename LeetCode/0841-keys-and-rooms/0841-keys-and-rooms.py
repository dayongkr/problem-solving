class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        opens = 1
        visited = [False for _ in range(n)]
        
        visited[0] = True
        stack = [0]

        while stack:
            top = stack.pop()
            keys = rooms[top]

            for key in keys:
                if not visited[key]:
                    opens += 1
                    visited[key] = True
                    stack.append(key)

        return opens == n