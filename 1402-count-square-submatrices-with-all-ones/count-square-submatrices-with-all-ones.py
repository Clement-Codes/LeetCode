class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:

        #bottom first
        ROW, COL = len(matrix), len(matrix[0])
        cache = defaultdict(int)
        result = 0

        for r in range(ROW):
            cache2 = defaultdict(int)
            for c in range(COL):
                if matrix[r][c]:    
                    cache2[c] = 1  + min(cache[c], cache2[c - 1], cache[c - 1])
                    result += cache2[c]
            cache = cache2
        return result 

        




        # dfs
        # ROW, COL, result, memo = len(matrix), len(matrix[0]), 0, {}


        # def dfs(r, c):
        #     if (r, c) in memo: return memo[(r, c)]
        #     if r == ROW or c == COL or not matrix[r][c]:
        #         return 0
        #     memo[(r, c)] = 1 + min(dfs(r + 1, c), dfs(r, c + 1), dfs(r + 1, c + 1))
        #     return memo[(r, c)]

        # for r in range(ROW):
        #     for c in range(COL):
        #         result += dfs(r, c)

        # return result



        #Bottom-Up
        # ROW = len(matrix)
        # COL = len(matrix[0])
        # memo = defaultdict(int)
        # for i in range(ROW):
        #     for j in range(COL):
        #         if matrix[i][j] != 0:
        #             a, b, c = 0, 0, 0
        #             if i > 0:
        #                 a = matrix[i - 1][j]
        #             if j > 0:
        #                 b = matrix[i][j - 1]
        #             if i > 0 and j > 0:
        #                 c = matrix[i - 1][j - 1]
        #             matrix[i][j] = matrix[i][j] + min(a, b, c)
        #             for k in range(1, matrix[i][j] + 1):
        #                 memo[k] += 1
        # return sum(list(memo.values()))
        