class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        distances = [[x**2 + y**2, x, y] for x, y in points]
        heapq.heapify(distances)
        result = []
        n = 0
        while n < k:
            temp = heapq.heappop(distances)
            result.append(temp[1:])
            n+=1
        return result
