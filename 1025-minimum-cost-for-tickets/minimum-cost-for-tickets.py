class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        memo = {
            len(days): 0
        }

        for i in reversed(range(len(days))):
            if i in memo:
                return memo[i]

            memo[i] = float("inf")
            for cost, day in zip(costs, [1, 7, 30]):
                j = i
                while j < len(days) and days[j] < days[i] + day:
                    j += 1
                memo[i] =  min(memo[i], cost + memo[j])

        return memo[0]
        
        # top-down
        # memo = {
        #     len(days): 0
        # }

        # def dfs(i):
        #     if i in memo:
        #         return memo[i]

        #     memo[i] = float("inf")
        #     for cost, day in zip(costs, [1, 7, 30]):
        #         j = i
        #         while j < len(days) and days[j] < days[i] + day:
        #             j += 1
        #         memo[i] =  min(memo[i], cost + dfs(j))
        #     return memo[i]

        # return dfs(0)
            
                



        # result = float("inf")

        # def dfs(index, curr, p):
        #     nonlocal result
        #     if len(days) == index:
        #         result = min(result, sum(p))
        #         print(index, curr, p)
        #         return
        #     for cost in costs:
        #         curr += cost
        #         while index < len(days) and curr >= days[index]:
        #             index += 1
        #         dfs(index, days[index] - 1 if index < len(days) else curr, p + [cost])
        
        # dfs(0, 0, [])
        # return result