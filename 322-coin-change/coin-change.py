class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        mapper = [amount + 1] * (amount+1)
        mapper[0]=0
        for i in range(amount+1):
            for c in coins:
                if i-c >= 0:
                    mapper[i] = min(mapper[i], 1 + mapper[i-c])
        return mapper[amount] if mapper[amount] != amount + 1 else -1