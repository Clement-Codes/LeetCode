class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        heap = []
        result = ""
        for i, j in [(-a, 'a'), (-b, 'b'), (-c, 'c')]:
            if i < 0:
                heapq.heappush(heap, (i, j))

        while heap:
            first_count, first_occ = heapq.heappop(heap)
            if len(result) > 1 and result[-1] == result[-2] == first_occ:
                if not heap:
                    break
                second_count, second_occ = heapq.heappop(heap)
                result += second_occ
                second_count += 1
                if second_count:
                    heapq.heappush(heap, (second_count, second_occ))
            else:
                result += first_occ
                first_count += 1
            if first_count:
                heapq.heappush(heap, (first_count, first_occ))
        return result