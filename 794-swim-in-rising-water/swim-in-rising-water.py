class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        N = len(grid)
        visited = set()
        h = [[grid[0][0],0,0]]
        t = 0
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        while h:
            k, i, j = heapq.heappop(h)
            print(i, j)
            visited.add((i, j))
            t = max(t, k)
            if i == N - 1 and j == N - 1: return t
            for di, dj in directions:
                di, dj = i + di, j + dj
                if di < 0 or dj < 0 or di == N or dj == N or (di, dj) in visited: continue
                heapq.heappush(h, (grid[di][dj], di, dj))
                
            
