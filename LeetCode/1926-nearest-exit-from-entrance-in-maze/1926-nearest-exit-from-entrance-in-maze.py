from collections import deque


class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        ROW, COL = len(maze) - 1, len(maze[0]) - 1
        direct = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        row, col, step = *entrance, 0

        queue = deque()
        queue.append((row, col, 0))
        maze[row][col] = "+"

        while queue:
            row, col, step = queue.popleft()
            step += 1

            for dr, dc in direct:
                n_row, n_col = row + dr, col + dc

                if ROW >= n_row >= 0 and COL >= n_col >= 0 and maze[n_row][n_col] == ".":
                    if n_row == 0 or n_row == ROW or n_col == 0 or n_col == COL:
                        return step
                    else:
                        maze[n_row][n_col] = "+"
                        queue.append((n_row, n_col, step))

        return -1
