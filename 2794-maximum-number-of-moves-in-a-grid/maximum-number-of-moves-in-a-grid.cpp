class Solution {
public:
    int ROW;
    int COL;
    int dfs(int r, int c, vector<vector<int>>& memo, vector<vector<int>>& grid){
        if (memo[r][c] != -1) return memo[r][c];
        if (c + 1 != COL){
            if (r > 0 && grid[r][c] < grid[r - 1][c + 1])
                memo[r][c] = 1 + dfs(r - 1, c + 1, memo, grid);
            if (grid[r][c] < grid[r][c + 1])
                memo[r][c] = max(memo[r][c], 1 + dfs(r, c + 1, memo, grid));
            if (r + 1 != ROW && grid[r][c] < grid[r + 1][c + 1])
                memo[r][c] = max(memo[r][c], 1 + dfs(r + 1, c + 1, memo, grid));              
        }
        return max(memo[r][c], 0);
    }
    int maxMoves(vector<vector<int>>& grid) {
        ROW = grid.size();
        COL = grid[0].size();
        int result = 0;
        vector<vector<int>> memo (ROW, vector<int>(COL, -1 ));
        for (int r = 0; r < ROW; r++)
            result = max(result, dfs(r, 0, memo, grid));
        return result;
    }
};