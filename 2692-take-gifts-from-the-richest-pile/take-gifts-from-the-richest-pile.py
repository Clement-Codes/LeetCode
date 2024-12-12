class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        heap = []
        for i in gifts:
            heapq.heappush(heap, -i)
        
        while k:
            
            heapq.heappush(heap, -1 * math.floor(math.sqrt(-1 * heapq.heappop(heap))))
            k -= 1
        return -1 * sum(heap)