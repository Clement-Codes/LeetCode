class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:

        ROW = len(grid)
        COL = len(grid[0])
        memo = [[-1 for _ in range(COL)] for _ in range(ROW)]


        def dfs(r, c):
            if memo[r][c] != -1: return memo[r][c]
            if c + 1 < COL:
                if r > 0 and grid[r][c] < grid[r - 1][c + 1]:
                    memo[r][c] = max(memo[r][c] , 1 + dfs(r - 1, c + 1))
                if  grid[r][c] < grid[r][c + 1]:
                    memo[r][c]  = max(memo[r][c], 1 + dfs(r, c + 1))
                if r + 1 < ROW and grid[r][c] < grid[r + 1][c + 1]:
                    memo[r][c] = max(memo[r][c], 1 + dfs(r + 1,c + 1))
            memo[r][c] = max(memo[r][c], 0)
            return memo[r][c]

        result = -1
        for r in range(ROW):
            result = max(result, dfs(r, 0)) 

        return result