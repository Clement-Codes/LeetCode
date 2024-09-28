class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        result = 0

        if not grid or not grid[0]: return result
        
        ROW = len(grid)
        COL = len(grid[0])
        visited = set()

        def dfs(i, j):
            queue = deque()
            queue.append((i,j))
            while queue:
                r, c = queue.popleft()
                directions = [[1,0], [0,1], [-1,0], [0,-1]]
                for rx, cx in directions:
                    rx = r+rx
                    cx = c+cx
                    if rx in range(ROW) and cx in range(COL) and (rx, cx) not in visited and grid[rx][cx] == "1":
                        queue.append((rx, cx))
                        visited.add((rx, cx))

        for i in range(ROW):
            for j in range(COL):
                if grid[i][j] == "1" and (i, j) not in visited:
                    dfs(i, j)
                    result += 1

        return result
            

        