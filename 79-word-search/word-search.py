class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        ROW = len(board)
        COL = len(board[0])
        path = set()
        def backtracking(row, col, index):
            
            if index == len(word): return True
            if 0 > row or row >= ROW or 0 > col or col >= COL or board[row][col] != word[index] or (row, col) in path: return False

            index += 1
            path.add((row, col))
            res = backtracking(row + 1, col, index) or backtracking(row - 1, col, index) or backtracking(row, col + 1, index) or backtracking(row, col - 1, index)
            path.remove((row, col))
            return res

        for i in range(ROW):
            for j in range(COL):
                if backtracking(i, j, 0):
                    return True
        return False