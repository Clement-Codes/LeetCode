class Solution {
    // HashMap<String, Integer> cache = new HashMap<String, Integer>();

    // public int dfs(int i, int a, int amount, int[] coins){
    //     if (a == amount) return 1;
    //     if (a > amount) return 0;
    //     if (i == coins.length) return 0;
    //     String key = String.valueOf(i) + "_" + String.valueOf(a);
    //     if (cache.containsKey(key)) return cache.get(key);
    //     cache.put(key, dfs(i+1, a, amount, coins) + dfs(i, a + coins[i], amount, coins));
    //     return cache.get(key);
    // }

    // public int change(int amount, int[] coins) {
    //     return dfs(0 , 0, amount, coins);    
    // }

    public int change(int amount, int[] coins) {
        int dp[][] = new int[amount + 1][coins.length + 1];
        for (int i = 0; i < amount + 1; i++){
            if (i == 0) Arrays.fill(dp[i], 1);
            else Arrays.fill(dp[i], 0);
        }

        for (int i = 1; i < amount + 1; i++){
            for (int j = coins.length - 1; j >= 0; j--){
                dp[i][j] = dp[i][j+1];
                if (i - coins[j] >= 0) dp[i][j] += dp[i - coins[j]][j];
            }
        }
        return dp[amount][0];
    }
}