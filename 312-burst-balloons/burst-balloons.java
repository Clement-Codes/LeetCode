class Solution {
    public int dfs(int l, int r, int[] nums, int[][] dp){
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        for (int i = l; i < r + 1; i++){
            int coins = nums[l - 1] * nums[i] * nums[r + 1];
            coins += dfs(l, i - 1, nums, dp) + dfs(i + 1, r, nums, dp);
            dp[l][r] = Math.max(dp[l][r], coins);
        }
        return dp[l][r];
    }

    public int maxCoins(int[] nums) {
        int n = nums.length;
        
        int temp[] = new int[n + 2];
        temp[0] = temp[n + 1] = 1;
        for(int i = 0; i < n; i++)
            temp[i + 1] = nums[i];
        
        int dp[][] = new int[n + 2][n + 2];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }

        return dfs(1, n, temp, dp);
    }
}