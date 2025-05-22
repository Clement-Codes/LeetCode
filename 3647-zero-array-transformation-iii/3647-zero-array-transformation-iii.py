class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        queries.sort()
        collection = []
        candidates = []

        n = len(nums)
        ans = 0
        j = 0
        
        for i in range(n):
            while (j< len(queries) and queries[j][0]==i):
                heapq.heappush(collection, -queries[j][1])
                j += 1

            nums[i] -= len(candidates)

            while nums[i] > 0 and len(collection) > 0 and -collection[0] >= i:
                heapq.heappush(candidates, -heapq.heappop(collection))
                nums[i] -= 1
                ans += 1

            if nums[i] > 0:
                return -1

            while len(candidates) > 0 and candidates[0] == i:
                heapq.heappop(candidates)

        return len(queries) - ans