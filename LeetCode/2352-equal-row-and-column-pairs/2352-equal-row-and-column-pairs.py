class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        rows = []
        cols = [[] for _ in range(len(grid))]

        for row in grid:
            rows.append(",".join(map(str, row)))

            for index, col in enumerate(row):
                cols[index].append(str(col))
        
        cols = list(map(lambda col: ",".join(col), cols))

        rowsDict = {}
        result = 0

        for row in rows:
            if row in rowsDict:
                rowsDict[row] += 1
            else:
                rowsDict[row] = 1
        
        for col in cols:
            if col in rowsDict:
                result += rowsDict[col]

        return result
