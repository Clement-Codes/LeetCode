class Solution {
public:
    int ROW = 0, COL = 0;

    int dfs(int r, int c, vector<vector<int>>& matrix, unordered_map<string, int>& memo){
        string key = to_string(r) + "_" + to_string(c);
        if (memo.contains(key)) return memo[key];
        if (r == ROW || c == COL || !matrix[r][c]) return 0;
        memo[key] = 1 + min(dfs(r + 1, c, matrix, memo), min(dfs(r, c + 1, matrix, memo), dfs(r + 1, c + 1, matrix, memo)));
        return memo[key];
    }

    int countSquares(vector<vector<int>>& matrix) {
        int result = 0;
        ROW = matrix.size();
        COL = matrix[0].size();
        unordered_map<string, int> memo;
        for (int r = 0; r < ROW; r++)
            for (int c = 0; c < COL; c++)
                result += dfs(r, c, matrix, memo);
        return result;
    }
};