class Solution {
    int row = 0;
    int col = 0;

    public void backtracking(int i, int j, char[][]grid){
        if(i<0 || j<0 || i == row || j == col || grid[i][j] == '0') return;
        grid[i][j] = '0';
        backtracking(i + 1, j, grid);
        backtracking(i - 1, j, grid);
        backtracking(i, j + 1, grid);
        backtracking(i, j - 1, grid);
    }

    public int numIslands(char[][] grid) {
        int result = 0;
        if (grid.length == 0 || grid[0].length == 0) return result;

        row = grid.length;
        col = grid[0].length;

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    backtracking(i, j, grid);
                    result += 1;
                }
            }

        return result;
    }
}