class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefix_1(grid[0].begin(), grid[0].end());
        vector<long long> prefix_2(grid[1].begin(), grid[1].end());

        for (int i = 1; i < n; i++){
            prefix_1[i] += prefix_1[i-1];
            prefix_2[i] += prefix_2[i-1];
        }

        long long result = LLONG_MAX;
        for (int i = 0; i < n; i++){
            long long top = prefix_1[n - 1] - prefix_1[i];
            long long bottom = i > 0 ? prefix_2[i - 1] : 0;
            long long second = max(top, bottom);
            result = min(result, second);
        }
        return result;
    }
};