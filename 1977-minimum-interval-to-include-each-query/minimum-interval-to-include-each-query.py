class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        intervals.sort()
        cache = {}
        minHeap = []
        l = 0
        for i in sorted(queries):
            
            while l < len(intervals) and intervals[l][0] <= i:
                heapq.heappush(minHeap, [(intervals[l][1] - intervals[l][0] + 1), intervals[l][1]])
                l += 1
            while minHeap and minHeap[0][1] < i:
                heapq.heappop(minHeap)
            
            cache[i] = minHeap[0][0] if minHeap else -1
        
        return [cache[i] for i in queries]