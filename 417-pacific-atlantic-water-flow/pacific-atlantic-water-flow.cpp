class Solution {
public:
    int row;
    int col;

    void dfs(int r, int c, vector<pair<int, int>>& visited, int prevHeight, vector<vector<int>>& heights){
        if (r < 0 || c < 0 || r == row || c == col || prevHeight > heights[r][c] || find(visited.begin(), visited.end(),pair<int, int>(r, c)) != visited.end()) return;
        visited.push_back(pair<int, int>(r, c));
        dfs(r + 1, c, visited, heights[r][c], heights);
        dfs(r - 1, c, visited, heights[r][c], heights);
        dfs(r, c + 1, visited, heights[r][c], heights);
        dfs(r, c - 1, visited, heights[r][c], heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();
        vector<pair<int, int>> pac;
        vector<pair<int, int>> alt;
        vector<vector<int>> result;

        for (int i = 0; i < col; i++){
            dfs(0, i, pac, heights[0][i], heights);
            dfs(row - 1, i, alt, heights[row-1][i], heights);
        }

        for (int i = 0; i < row; i++){
            dfs(i, 0, pac, heights[i][0], heights);
            dfs(i, col - 1, alt, heights[i][col - 1], heights);
        }

        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (find(pac.begin(), pac.end(), pair<int,int>(i, j)) != pac.end() && find(alt.begin(), alt.end(), pair<int,int>(i, j)) != alt.end()){
                    result.push_back(vector<int>{i, j});
                }
            }
        }

        return result;
    }
};