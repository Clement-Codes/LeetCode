class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        ROW = len(grid)
        COL = len(grid[0])
        heap = [(0, 0, 0)]
        visited = set()
        visited.add((0, 0))
        while heap:
            v, px, py = heapq.heappop(heap)
            if px == ROW - 1 and py == COL - 1:
                return v
            for x, y in [[px + 1, py], [px - 1, py], [px, py + 1], [px, py - 1]]:
                if 0 <= x and 0 <= y and x < ROW and y < COL:
                    if (x, y) not in visited:
                        heapq.heappush(heap, (v + grid[x][y], x, y))
                        visited.add((x, y))
