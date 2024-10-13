class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        heap = []
        start = 0
        end = float("inf")
        result = []
        currMax = float("-inf")

        for i in range(len(nums)):
            heapq.heappush(heap, [nums[i][0], i, 0])
            currMax = max(currMax, nums[i][0])

        while len(heap) == len(nums):
            curr = heapq.heappop(heap)
            
            if currMax - curr[0] < end - start:
                start = curr[0]
                end = currMax
            
            if curr[2]  + 1 < len(nums[curr[1]]):
                heapq.heappush(heap, [nums[curr[1]][curr[2] + 1], curr[1], curr[2] + 1])
                currMax = max(currMax, nums[curr[1]][curr[2] + 1])
        return [start, end]

