class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        heap = []
        result = float("inf")
        s = 0
        for r in range(len(nums)):
            s += nums[r]

            if s >= k:
                result = min(result, r + 1)
            
            while heap and s - heap[0][0] >= k:
                temp = heapq.heappop(heap)
                result = min(result, r - temp[1])
            heapq.heappush(heap, (s, r))

        return -1 if result == float("inf") else result