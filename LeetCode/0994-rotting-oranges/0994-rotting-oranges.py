from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        ds = [(-1, 0), (0, 1), (1, 0), (0, -1)]

        freshOrange = 0

        minute = 0
        queue = deque()

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    queue.append((r, c, 0))
                elif grid[r][c] == 1:
                    freshOrange += 1

        if freshOrange == 0:
            return 0

        while queue:
            r, c, m = queue.popleft()

            for dr, dc in ds:
                nr, nc, nm = r + dr, c + dc, m + 1

                if 0 <= nr < rows and 0 <= nc < cols:
                    cur = grid[nr][nc]
                    
                    if cur == 1:
                        freshOrange -= 1
                    
                    if cur != 0:
                        queue.append((nr, nc, nm))
                        grid[nr][nc] = 0
            
                if freshOrange == 0:
                    return nm

        return -1