class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort(key = lambda x : x[0])
        heap = []
        maxSum = 0
        maxCarry = 0
        for event in events:
            while heap and heap[0][0] < event[0]:
                maxCarry = max(maxCarry, heap[0][1])
                heapq.heappop(heap)
            maxSum = max(maxSum, maxCarry + event[2])
            heapq.heappush(heap, (event[1], event[2]))
        return maxSum