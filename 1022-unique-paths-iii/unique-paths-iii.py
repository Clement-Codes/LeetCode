class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        result = 0
        start = None
        cover = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    start = (i, j)
                elif grid[i][j] == 0:
                    cover += 1

        def dfs(x, y, curr):
            nonlocal result
            if grid[x][y] == -1:
                return
            if grid[x][y] == 2:
                if curr == cover:
                    result += 1
                return 
            for i, j in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                ii, jj = i + x, j + y
                
                if 0 > ii or ii == row or 0 > jj or jj == col or grid[ii][jj] == -1:
                    continue
                
                grid[x][y] = -1
                dfs(ii, jj, (curr + 1) if grid[ii][jj] == 0 else curr)
                grid[x][y] = 0

        dfs(start[0], start[1], 0)
        return result
