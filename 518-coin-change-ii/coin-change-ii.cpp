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

    // int change(int amount, vector<int>& coins) {
    //     unsigned long long** dp = new unsigned long long*[amount+1];
    
    //     for (int i = 0; i < amount + 1; i++){
    //         dp[i] = new unsigned long long[coins.size() + 1];
    //         if (i == 0){
    //             fill_n(dp[i], coins.size() + 1, 1);
    //         }
    //         else{
    //             fill_n(dp[i], coins.size() + 1, 0);
    //         }
    //     }

    //     for (int i = 1; i < amount + 1; i++){
    //         for (int j = coins.size() - 1; j >=0 ; j--){
    //             dp[i][j] = dp[i][j+1];
    //             if (i - coins[j] >=0){
    //                 dp[i][j] += dp[i - coins[j]][j];
    //             }
    //         }
    //     }
    //     return dp[amount][0];
    // }

    int change(int amount, vector<int>& coins) {
        unsigned long long* dp = new unsigned long long[amount + 1];
        fill_n(dp, amount+1, 0);
        dp[0] = 1;
        for (int i = coins.size() - 1; i >= 0; i--){
            unsigned long long* temp = new unsigned long long[amount + 1];
            fill_n(temp, amount+1, 0);
            temp[0] = 1;
            for (int a = 1; a < amount + 1; a++){
                temp[a] = dp[a];
                if (a - coins[i] >= 0)
                {
                    temp[a] += temp[a - coins[i]];
                }
            }
            dp = temp;
        }
        return dp[amount];
    }
};