class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        firstRow = False
        ROW = len(matrix)
        COL = len(matrix[0])

        for i in range(ROW):
            for j in range(COL):
                if matrix[i][j] == 0:
                    matrix[0][j] = 0
                    if i == 0:
                        firstRow = True
                    else:
                        matrix[i][0] = 0
        
        for i in range(1, ROW):
            for j in range(1, COL):
                if matrix[0][j] == 0 or matrix[i][0] == 0:
                    matrix[i][j] = 0
        
        if matrix[0][0] == 0:
            for i in range(ROW):
                matrix[i][0] = 0
        
        if firstRow:
            for i in range(COL):
                matrix[0][i] = 0
