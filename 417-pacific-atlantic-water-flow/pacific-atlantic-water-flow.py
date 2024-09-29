class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        row = len(heights)
        col = len(heights[0])
        pac = set()
        atl = set()
        result = []

        def dfs(r, c, visit, pastHeight):
            if r < 0 or c < 0 or r == row or c == col or pastHeight>heights[r][c] or (r, c) in visit: return
            visit.add((r, c))
            dfs(r + 1, c, visit, heights[r][c])
            dfs(r - 1, c, visit, heights[r][c])
            dfs(r, c + 1, visit, heights[r][c])
            dfs(r, c - 1, visit, heights[r][c])

        
        for i in range(col):
            dfs(0, i, pac, heights[0][i])
            dfs(row-1, i, atl, heights[row-1][i])
        
        for i in range(row):
            dfs(i, 0, pac, heights[i][0])
            dfs(i, col - 1, atl, heights[i][col - 1])
        
        for i in range(row):
            for j in range(col):
                if (i, j) in pac and (i, j) in atl:
                    result.append([i, j])

        return result