class Solution {
    int ROW;
    int COL;
    int dfs(int r, int c, int memo[][], int grid[][]){
        if (memo[r][c] != -1) return memo[r][c];
        if (c + 1 != COL){
            if (r > 0 && grid[r][c] < grid[r - 1][c + 1])
                memo[r][c] = 1 + dfs(r - 1, c + 1, memo, grid);
            if (grid[r][c] < grid[r][c + 1])
                memo[r][c] = Math.max(memo[r][c], 1 + dfs(r, c + 1, memo, grid));
            if (r + 1 != ROW && grid[r][c] < grid[r + 1][c + 1])
                memo[r][c] = Math.max(memo[r][c], 1 + dfs(r + 1, c + 1, memo, grid));              
        }
        return Math.max(memo[r][c], 0);
    }
    public int maxMoves(int[][] grid) {
        ROW = grid.length;
        COL = grid[0].length;
        int result = 0;
        int memo[][] = new int[ROW][COL];
        for (int temp[]: memo)
            Arrays.fill(temp, -1);
        for (int r = 0; r < ROW; r++)
            result = Math.max(result, dfs(r, 0, memo, grid));
        return result;
    }
}