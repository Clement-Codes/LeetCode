class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        cache = {}
        def dfs(i, j):
            if i > j: return 0
            if (i, j) in cache: return cache[(i, j)]
            cache[(i, j)] = 0
            for k in range(i, j+1):
                coins = nums[i - 1] * nums[k] * nums[j + 1]
                coins += dfs(i, k - 1) + dfs(k + 1, j)
                cache[(i, j)] = max(cache[(i, j)], coins)
            return cache[(i,j)]
        return dfs(1, len(nums) - 2)