class Solution {
    int n;
    int neighbours[][] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    boolean outOfBounds(int r, int c){
        return (r < 0 || c < 0 || r == n || c == n);
    }

    int dfs(int r, int c, int label, int grid[][]){
        if (outOfBounds(r, c) || grid[r][c] != 1)
            return 0;

        grid[r][c] = label;
        int size = 1;
        for (int neighbour[] : neighbours)
            size += dfs(r + neighbour[0], c + neighbour[1], label, grid);
        return size;
    }

    int connect(int r, int c, int[][] grid, HashMap<Integer, Integer> sizes){
        int res = 1;
        HashSet<Integer> visited = new HashSet<Integer>();
        visited.add(0);
        for (int neighbour[]: neighbours){
            if (!outOfBounds(r + neighbour[0], c + neighbour[1]) && !visited.contains(grid[r + neighbour[0]][c + neighbour[1]]))
            {
                res += sizes.get(grid[r + neighbour[0]][c + neighbour[1]]);
                visited.add(grid[r + neighbour[0]][c + neighbour[1]]);
            }
        }
        return res;
    }

    public int largestIsland(int[][] grid) {
        n = grid.length;
        HashMap<Integer, Integer> sizes = new HashMap<Integer, Integer>();
        int res = 0;
        int label = 2;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1){
                    sizes.put(label, dfs(i, j, label, grid));
                    res = Math.max(res, sizes.get(label));
                    label += 1;
                }
            
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                    res = Math.max(res, connect(i, j, grid, sizes));
        
        return res;
    }
}