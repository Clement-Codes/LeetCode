class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        df = [0 for _ in range(amount + 1) ]
        df[0] = 1
        for i in range(len(coins) - 1, -1, -1):
            temp = [0 for _ in range(amount + 1)]
            temp[0] = 1
            for j in range(1, amount + 1):
                temp[j] = df[j]
                if j - coins[i] >=0:
                    temp[j] += temp[j - coins[i]]
            df = temp
        return df[amount] 

        # df = [[0 for _ in range(len(coins) + 1)] for _ in range(amount + 1)]
        # df[0] = [1 for _ in range(len(coins) + 1)]

        # for i in range(1, amount + 1):
        #     for j in range(len(coins) - 1, -1, -1):
        #         df[i][j] = df[i][j+1]
        #         if i - coins[j]>=0:
        #             df[i][j] += df[i - coins[j]][j]


        # return df[amount][0]

        # catche = {}

        # def dfs(i, a):
        #     if a == amount: return 1
        #     if a > amount: return 0
        #     if i == len(coins): return 0
        #     if (i, a) in catche: return catche[(i, a)]

        #     catche[(i, a)] = dfs(i+1, a) + dfs(i, a + coins[i])
        #     return catche[(i, a)]
        # return dfs(0,0)