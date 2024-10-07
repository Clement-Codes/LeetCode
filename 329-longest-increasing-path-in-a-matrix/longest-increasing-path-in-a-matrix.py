class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        row, col = len(matrix), len(matrix[0])
        
        dp = {}

        def dfs(i, j, prevVal):
            if (i < 0 or j < 0 or i == row or j == col or matrix[i][j] <= prevVal): return 0
            if (i, j) in dp: return dp[(i, j)]
            
            res = 1
            res = max(res, 1 + dfs(i + 1, j, matrix[i][j]))
            res = max(res, 1 + dfs(i - 1, j, matrix[i][j]))
            res = max(res, 1 + dfs(i, j + 1, matrix[i][j]))
            res = max(res, 1 + dfs(i, j - 1, matrix[i][j]))
            dp[(i, j)] = res
            return res
        
        for i in range(row):
            for j in range(col):
                dfs(i, j, -1)
        
        return max(dp.values())
