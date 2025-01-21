class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        n = len(grid[0])

        prefix_1 = grid[0].copy()
        prefix_2 = grid[1].copy()

        for i in range(1, n):
            prefix_1[i] += prefix_1[i - 1]
            prefix_2[i] += prefix_2[i - 1]
        
        res = float("inf")
        for i in range(n):
            top = prefix_1[-1] - prefix_1[i]
            bottom = prefix_2[i - 1] if i > 0 else 0
            second = max(top, bottom)
            res = min(res, second)
        
        return res