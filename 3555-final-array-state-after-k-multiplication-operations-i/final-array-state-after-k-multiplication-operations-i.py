class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        heap = []
        n = len(nums)
        for i in range(n):
            heapq.heappush(heap, (nums[i],i))
        while k:
            temp = heapq.heappop(heap)
            heapq.heappush(heap, (temp[0] * multiplier, temp[1]))
            k -= 1
        result = [0] * n
        while heap:
            temp = heapq.heappop(heap)
            result[temp[1]] = temp[0]
        return result
