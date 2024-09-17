class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row, col = len(matrix), len(matrix[0])
        brow, frow = 0 , row - 1
        while brow <= frow:
            midrow = brow + ((frow - brow) // 2)
            if target > matrix[midrow][-1]:
                brow = midrow + 1
            elif target < matrix[midrow][0]:
                frow = midrow - 1
            else:
                break
        
        if not brow<=frow: return False

        bcol, fcol = 0, col -1
        mrow = brow + ((frow - brow) // 2)
        while bcol<=fcol:
            
            mcol = bcol + ((fcol - bcol) //2)
            if target > matrix[mrow][mcol]:
                bcol = mcol + 1
            elif target < matrix[mrow][mcol]:
                fcol = mcol - 1
            else: return True
        return False