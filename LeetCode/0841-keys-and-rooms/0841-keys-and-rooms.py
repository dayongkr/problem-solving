class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        opens = 1
        
        stack = [0]
        visited = set(stack)

        while stack:
            top = stack.pop()
            keys = rooms[top]

            for key in keys:
                if key not in visited:
                    opens += 1
                    visited.add(key)
                    stack.append(key)

        return opens == n