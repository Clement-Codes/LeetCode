class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length;
        int col = matrix[0].length;

        int brow = 0;
        int erow = row - 1;
        while(brow <= erow){
            int mrow = brow + ((erow - brow)/ 2);
            if(target > matrix[mrow][col - 1]) brow = mrow + 1;
            else if (target < matrix[mrow][0]) erow = mrow - 1;
            else break;
        }

        if(brow>erow) return false;

        int bcol = 0;
        int ecol = col - 1;
        int mrow = brow + ((erow - brow)/ 2);

        while(bcol <= ecol){
            int mcol= bcol + ((ecol - bcol)/ 2);
            if(target > matrix[mrow][mcol]) bcol = mcol + 1;
            else if (target < matrix[mrow][mcol]) ecol = mcol - 1;
            else return true;
        }

        return false;
    }
}