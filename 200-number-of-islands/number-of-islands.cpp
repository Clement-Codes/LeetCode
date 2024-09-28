class Solution {
public:
    int row;
    int col;

    void backtracking(int i, int j, unordered_set<string>& visited, vector<vector<char>>&grid){
        queue<pair<int,int>> q;
        pair<int, int> temp(i, j);
        q.push(temp);
        while (q.size() > 0){
            pair<int, int> t = q.front();
            q.pop();
            visited.insert(to_string(t.first) + ',' + to_string(t.second));
            int directions[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
            for(auto tt: directions){
                int nr = t.first + tt[0];
                int nc = t.second + tt[1];
                if(nr>=0 && nr < row && nc >=0 && nc < col && !visited.contains(to_string(nr) + ',' + to_string(nc)) && grid[nr][nc] == '1'){
                    backtracking(nr, nc, visited, grid);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        if (grid.size() == 0 or grid[0].size() == 0) return result;

        row = grid.size();
        col = grid[0].size();
        unordered_set<string> visited;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++){
                if (!visited.contains(to_string(i) + ',' + to_string(j)) && grid[i][j] == '1'){
                    backtracking(i, j, visited, grid);
                    result+=1;
                }
            }
        return result;
    }
};