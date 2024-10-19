class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = defaultdict(set)
        cols = defaultdict(set)
        boxs = defaultdict(set)
        ROW = len(board)
        COL = len(board[0])

        for i in range(ROW):
            for j in range(COL):
                if board[i][j] == '.':
                    continue
                if board[i][j] in rows[i] or board[i][j] in cols[j] or board[i][j] in boxs[(i//3, j//3)]:
                    return False
                rows[i].add(board[i][j])
                cols[j].add(board[i][j])
                boxs[(i//3, j//3)].add(board[i][j])
        return True



















        # valid_row = defaultdict(set)
        # valid_col = defaultdict(set)
        # valid_box = defaultdict(set)
        # for i in range(len(board)):
        #     for j in range(len(board)):
        #         if board[i][j] == '.':
        #             continue
        #         if board[i][j] in valid_row[i] or board[i][j] in valid_col[j] or board[i][j] in valid_box[(i//3,j//3)]:
        #             print(board[i][j] in valid_row[i])
        #             print(board[i][j] in valid_col[j])
        #             print(board[i][j] in valid_box[(i//3,j//3)])

        #             return False
        #         valid_row[i].add(board[i][j]) 
        #         valid_col[j].add(board[i][j])
        #         valid_box[(i//3,j//3)].add(board[i][j])
        # return True