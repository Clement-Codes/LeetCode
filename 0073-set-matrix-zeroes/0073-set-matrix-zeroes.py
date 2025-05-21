class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        ROWS, COLS = len(matrix), len(matrix[0])
        
        first_row = False

        for i in range(ROWS):
            for j in range(COLS):
                if matrix[i][j] != 0:
                    continue
                matrix[0][j] = 0
                if i > 0:
                    matrix[i][0] = 0
                else:
                    first_row = True
        
        for i in range(1, ROWS):
            for j in range(1, COLS):
                if matrix[0][j] == 0:
                    matrix[i][j] = 0
                if matrix[i][0] == 0:
                    matrix[i][j] = 0
        
        if matrix[0][0] == 0:
            for i in range(1, ROWS):
                matrix[i][0] = 0
        
        if first_row:
            for j in range(COLS):
                matrix[0][j] = 0

    
