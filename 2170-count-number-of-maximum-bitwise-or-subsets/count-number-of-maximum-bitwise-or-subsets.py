class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        # # Brute Force
        # max_or = 0
        # for i in nums:
        #     max_or |= i
        # result = 0

        # def dfs(i, curr):
        #     nonlocal result
        #     if i  == len(nums): 
        #         if curr == max_or:
        #             result += 1
        #         return
        #     dfs(i + 1, curr)
        #     dfs(i + 1, curr | nums[i])
        # dfs(0, 0)
        # return result 

        # Brute Force with no variable
        # max_or = 0
        # for i in nums:
        #     max_or |= i
        # def dfs(i, curr):
        #     if i  == len(nums): 
        #         return 1 if curr == max_or else 0
        #     return dfs(i + 1, curr) + dfs(i + 1, curr | nums[i])
        # return dfs(0, 0) 

        #Memoization
        # max_or = 0
        # for i in nums:
        #     max_or |= i
        # cache = {}
        # def dfs(i, curr):
        #     if (i, curr) in cache:
        #         return cache[(i, curr)]
        #     if i  == len(nums): 
        #         return 1 if curr == max_or else 0
        #     cache[(i, curr)] = dfs(i + 1, curr) + dfs(i + 1, curr | nums[i])
        #     return cache[(i, curr)]
        # return dfs(0, 0) 

        #bottom-up
        max_or = 0
        for i in nums:
            max_or |= i
        cache = {}
        cache[0] = 1
        i = 0
        while True:
            if i == len(nums):
                break
            clone = deepcopy(cache)
            for j in cache.keys():
                clone[j | nums[i]] = clone.get(j | nums[i], 0) + cache[j]
            cache = clone
            i += 1
        return cache[max_or]