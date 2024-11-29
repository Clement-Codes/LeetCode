class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if min(grid[0][1], grid[1][0]) > 1:
            return -1
        row = len(grid)
        col = len(grid[0])
        heap = [(0, 0, 0)]
        visited = set([(0,0)])
        while heap:
            t, px, py = heapq.heappop(heap)
            if (px, py) == (row - 1, col - 1):
                return t
            for x, y in [[px + 1, py], [px - 1, py], [px, py + 1], [px, py - 1]]:
                if 0 > x or 0 > y or x == row or y == col or (x, y) in visited:
                    continue
                wait = 0
                if abs(t - grid[x][y]) % 2 == 0:
                    wait = 1
                heapq.heappush(heap, (max(grid[x][y] + wait, t + 1), x, y))
                visited.add((x, y))
        return -1
