class Solution {
    int result = 0, row = 0, col = 0, coverage = 0;
    int directions[][] = {{1,0}, {0,1}, {-1,0}, {0, -1}};

    void dfs(int r, int c, int curr, int[][] grid){
        if (grid[r][c] == -1){
            return;
        }

        if (grid[r][c] == 2){
            if(curr == coverage){
                result++;
            }
            return;
        }

        for (int[] direction: directions)
        {
            int x = direction[0] + r;
            int y = direction[1] + c;
            if (0 > x || 0 > y || x == row || y == col || grid[x][y] == -1)
                continue;
            
            grid[r][c] = -1;
            dfs(x, y, (grid[x][y] == 0 ? curr + 1 : curr), grid);
            grid[r][c] = 0;
        }
    }

    public int uniquePathsIII(int[][] grid) {
        row = grid.length;
        col = grid[0].length;
        int start[] = new int[2]; 
        coverage = 0;
        for (int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                if (grid[r][c] == 1){
                    start[0] = r;
                    start[1] = c;
                }
                else if (grid[r][c] == 0){
                    coverage++;
                }
            }
        }

        dfs(start[0], start[1], 0, grid);
        return result;
    }
}