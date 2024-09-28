class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        visited = set()
        area = 0

        def dfs(r, c):
            if r<0 or c<0 or r == row or c == col or grid[r][c] == 0 or (r,c) in visited: return 0

            visited.add((r, c))
            return 1+dfs(r-1, c)+dfs(r+1, c)+dfs(r, c + 1)+dfs(r, c - 1)


        for r in range(row):
            for c in range(col):
                area = max(area, dfs(r, c))
        return area