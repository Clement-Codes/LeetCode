class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mapper = {}
        
        def dfs(i, task):
            if i >= len(prices): return 0
            if (i, task) in mapper: return mapper[(i, task)]

            if task:
                buying = dfs(i+1, not task) - prices[i]
                cooldown = dfs(i+1, task)
                mapper[(i, task)] = max(buying, cooldown)
            else:
                selling = dfs(i+2, not task) + prices[i]
                cooldown = dfs(i+1, task)
                mapper[(i, task)] = max(selling, cooldown)

            return mapper[(i, task)]
        
        return dfs(0, True)