class Solution {
    HashMap<String, Integer> cache = new HashMap<String, Integer>();

    public int dfs(int i, int a, int amount, int[] coins){
        if (a == amount) return 1;
        if (a > amount) return 0;
        if (i == coins.length) return 0;
        String key = String.valueOf(i) + "_" + String.valueOf(a);
        if (cache.containsKey(key)) return cache.get(key);
        cache.put(key, dfs(i+1, a, amount, coins) + dfs(i, a + coins[i], amount, coins));
        return cache.get(key);
    }

    public int change(int amount, int[] coins) {
        return dfs(0 , 0, amount, coins);    
    }
}