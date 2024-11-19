class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        result = 0
        l = 0
        s = 0
        prev_index = {}
        for r in range(n):
            s += nums[r]
            i = prev_index.get(nums[r], -1)

            while l <= i or r - l + 1 > k:
                s -= nums[l]
                l += 1
            
            if r - l + 1 == k:
                result = max(result, s)
            
            prev_index[nums[r]] = r
        return result        

        #Using map
        # n = len(nums)
        # result = 0
        # visited = defaultdict(int)
        # l = 0
        # s = 0
        # for r in range(n):
        #     visited[nums[r]] += 1
        #     s += nums[r]

        #     if r - l + 1 > k:
        #         if visited[nums[l]] == 1:
        #             del visited[nums[l]]
        #         else:
        #             visited[nums[l]] -= 1
        #         s -= nums[l]
        #         l += 1
            
        #     if r - l + 1 == k and len(visited) == k:
        #         result = max(result, s)
        # return result        

        # n = len(nums)
        # l = 0
        # result = 0
        # s = 0
        # visited = defaultdict(int)
        # for r in range(n):
        #     s += nums[r]
        #     visited[nums] += 1

        #     if r - l + 1 > k:
        #         s -= nums[l]
        #         l += 1
            
        #     if r - l + 1 == k:
        #         result = max(result, s)
        # return result