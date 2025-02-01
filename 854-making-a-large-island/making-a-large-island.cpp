class Solution {
public:
    int n;
    int neighbours [4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int outOfBounds(int r, int c){
        return (r < 0 or c < 0 or r == n or c == n);
    }

    int dfs(int r, int c, int label, vector<vector<int>>& grid){
        if (outOfBounds(r, c) or grid[r][c] != 1)
            return 0;

        grid[r][c] = label;
        int size = 1;
        for (auto neighbour : neighbours)
            size += dfs(r + neighbour[0], c + neighbour[1], label, grid);
        return size;
    }

    int connect(int r, int c, vector<vector<int>>& grid,unordered_map<int, int>& sizes){
        int res = 1;
        unordered_set<int> visited;
        visited.insert(0);
        for (auto neighbour : neighbours){
            if (!outOfBounds(r + neighbour[0], c + neighbour[1]) && !visited.contains(grid[r + neighbour[0]][c + neighbour[1]]))
            {
                 
                res += sizes[grid[r + neighbour[0]][c + neighbour[1]]];
                visited.insert(grid[r + neighbour[0]][c + neighbour[1]]);
            }
        }
        return res;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> sizes;
        int res = 0;

        int label = 2;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1){
                    sizes[label] = dfs(i, j, label, grid);
                    res = max(res, sizes[label]);
                    label += 1;
                }
            
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                    res = max(res, connect(i, j, grid, sizes));
        
        return res;
    }
};