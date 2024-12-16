class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        heap = []
        n = len(nums)
        for i in range(n):
            heapq.heappush(heap, (nums[i],i))
        while k:
            temp = heapq.heappop(heap)
            nums[temp[1]] *= multiplier
            heapq.heappush(heap, (nums[temp[1]], temp[1]))
            k -= 1
        return nums
