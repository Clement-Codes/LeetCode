class Solution {
public:
    int dfs(int l, int r, vector<int>& nums, vector<vector<int>>& dp){
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int result = 0;
        for (int i = l; i < r+1; i++){
            int coins = nums[l - 1] * nums[i] * nums[r + 1];
            coins += dfs(l, i - 1, nums, dp) + dfs(i + 1, r, nums, dp);
            result = max(result, coins);
        }
        dp[l][r] = result;
        return result;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp (nums.size(), vector<int>(nums.size(), -1));
        return dfs(1, nums.size() - 2, nums, dp);
    }
};