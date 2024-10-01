class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        mapper = {i: [] for i in range(len(points))}
        for i in range(len(points)):
            x, y = points[i]
            for j in range(i + 1, len(points)):
                sx, sy = points[j]
                distance = abs(x-sx) + abs(y-sy)
                mapper[i].append([distance, j])
                mapper[j].append([distance, i])
                
        heap = [[0,0]]
        visited = set()
        result = 0
        while len(visited) < len(points):
            temp = heapq.heappop(heap)
            if temp[1] in visited:
                continue
            result += temp[0]
            visited.add(temp[1])
            for point in mapper[temp[1]]:
                if point[1] not in visited:
                    heapq.heappush(heap, point) 
        return result