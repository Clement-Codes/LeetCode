class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        col = []
        pos = []
        neg = []
        result = []
        board = [['.'] * n for nn in range(n)]
        def backtracking(i):
            if i == n:
                result.append([''.join(row) for row in board])
                return
            for j in range(n):
                if j not in col and (i+j) not in pos and (i - j) not in neg:
                    board[i][j] = "Q"
                    col.append(j)
                    pos.append(i+j)
                    neg.append(i - j)
                    backtracking(i+1)
                    col.pop()
                    pos.pop()
                    neg.pop()
                    board[i][j] = "."
                    

        backtracking(0)
        return result 