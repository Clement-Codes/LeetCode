class Solution {
public:
    unordered_map<string, int> catche;

    int dfs(int i, int a, int amount, vector<int>& coins){
        if (a > amount) return 0;
        if (a == amount) return 1;
        if (i == coins.size()) return 0;
        string key = to_string(i) + "_" + to_string(a);
        if (catche.contains(key)) return catche[key];

        catche[key] = dfs(i + 1, a, amount, coins) + dfs(i, a + coins[i], amount, coins);
        return catche[key];
    }

    int change(int amount, vector<int>& coins) {
        return dfs(0,0, amount, coins);

    }
};