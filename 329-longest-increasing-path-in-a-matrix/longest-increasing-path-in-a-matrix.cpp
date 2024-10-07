bool compare(const pair<string, int>& a, const pair<string, int>& b){
    return a.second < b.second;
}
class Solution {
public:
    unordered_map<string, int> cache;
    int row = 0;
    int col = 0;
    
    int dfs(int i, int j, int prevValue, vector<vector<int>>& matrix){
        if (i < 0 || j < 0 || i == row || j == col || matrix[i][j] <= prevValue) return 0;
        string key = to_string(i) + "_" + to_string(j);
        if (cache.contains(key)) return cache[key];
        int res = 1;
        res = max(res, 1 + dfs(i + 1, j, matrix[i][j], matrix));
        res = max(res, 1 + dfs(i - 1, j, matrix[i][j], matrix));
        res = max(res, 1 + dfs(i, j + 1, matrix[i][j], matrix));
        res = max(res, 1 + dfs(i, j - 1, matrix[i][j], matrix));
        cache[key] = res;
        return res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                dfs(i, j, -1, matrix);
        return max_element(cache.begin(), cache.end(), compare)->second;  
    }
};