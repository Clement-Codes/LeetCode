class Solution {
    public int coinChange(int[] coins, int amount) {
        int mapper[] = new int[amount+1];
        Arrays.fill(mapper, amount+1);
        mapper[0] = 0;
        for (int i = 0; i < amount+1; i++)
            for (int coin: coins){
                if (i - coin >= 0){
                    mapper[i] = Math.min(mapper[i], 1 + mapper[i-coin]);
                }
            }
        return mapper[amount] == amount + 1 ? -1 : mapper[amount];
    }
}