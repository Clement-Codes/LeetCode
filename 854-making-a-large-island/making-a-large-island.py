class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)

        neighbour = [[1, 0], [0, 1], [-1, 0], [0, -1]]

        def outOfBounds(r, c):
            return (0 > r or r == n or 0 > c or c == n)

        def dfs(r, c, label):
            if (outOfBounds(r, c) or grid[r][c] != 1):
                return 0
            grid[r][c] = label
            size = 1
            queue = []
            for i, j in neighbour:
                size += dfs(r + i, c + j, label)
            return size

        size = defaultdict(int)
        curr_label = 2
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    size[curr_label] = dfs(i, j, curr_label)
                    curr_label += 1 


        def connect(r, c):
            visit = set()
            res = 1
            for i, j in neighbour:
                if not outOfBounds(r + i, c + j) and grid[r + i][c + j] not in visit:
                    res += size[grid[r + i][c + j]]
                    visit.add(grid[r + i][c + j])
            return res

        res =  0 if not size else max(size.values())
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    res = max(res, connect(i, j))

        return res

