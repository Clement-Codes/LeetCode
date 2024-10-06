class Solution {
public:
    // unordered_map<string, int> catche;

    // int dfs(int i, int a, int amount, vector<int>& coins){
    //     if (a > amount) return 0;
    //     if (a == amount) return 1;
    //     if (i == coins.size()) return 0;
    //     string key = to_string(i) + "_" + to_string(a);
    //     if (catche.contains(key)) return catche[key];

    //     catche[key] = dfs(i + 1, a, amount, coins) + dfs(i, a + coins[i], amount, coins);
    //     return catche[key];
    // }

    // int change(int amount, vector<int>& coins) {
    //     // return dfs(0,0, amount, coins);
    // }

    int change(int amount, vector<int>& coins) {
        unsigned long long** dp = new unsigned long long*[amount+1];
    
        for (int i = 0; i < amount + 1; i++){
            dp[i] = new unsigned long long[coins.size() + 1];
            if (i == 0){
                fill_n(dp[i], coins.size() + 1, 1);
            }
            else{
                fill_n(dp[i], coins.size() + 1, 0);
            }
        }

        for (int i = 1; i < amount + 1; i++){
            for (int j = coins.size() - 1; j >=0 ; j--){
                dp[i][j] = dp[i][j+1];
                if (i - coins[j] >=0){
                    dp[i][j] += dp[i - coins[j]][j];
                }
            }
        }
        return dp[amount][0];
    }
};