class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        valid_row = defaultdict(set)
        valid_col = defaultdict(set)
        valid_box = defaultdict(set)
        for i in range(len(board)):
            for j in range(len(board)):
                if board[i][j] == '.':
                    continue
                elif board[i][j] in valid_row[i] or board[i][j] in valid_col[j] or board[i][j] in valid_box[(i//3,j//3)]:
                    return False
                valid_row[i].add(board[i][j]) 
                valid_col[j].add(board[i][j])
                valid_box[(i//3,j//3)].add(board[i][j])
        return True