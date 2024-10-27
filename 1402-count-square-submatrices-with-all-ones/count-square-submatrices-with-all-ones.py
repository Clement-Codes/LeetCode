class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        ROW = len(matrix)
        COL = len(matrix[0])
        memo = defaultdict(int)
        for i in range(ROW):
            for j in range(COL):
                if matrix[i][j] != 0:
                    a, b, c = 0, 0, 0
                    if i > 0:
                        a = matrix[i - 1][j]
                    if j > 0:
                        b = matrix[i][j - 1]
                    if i > 0 and j > 0:
                        c = matrix[i - 1][j - 1]
                    matrix[i][j] = matrix[i][j] + min(a, b, c)
                    for k in range(1, matrix[i][j] + 1):
                        memo[k] += 1
        return sum(list(memo.values()))
        