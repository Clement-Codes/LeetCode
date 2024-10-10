class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        bool firstRow = false;
        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COL; j++)
                if (matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    if (i > 0){
                        matrix[i][0] = 0;
                    }
                    else{
                        firstRow = true;
                    }
                }
                
        for (int i = 1; i < ROW; i++)
            for (int j = 1; j < COL; j++)
                if (matrix[0][j] == 0 or matrix[i][0] == 0)
                    matrix[i][j] = 0;
                
        if (matrix[0][0] == 0)
            for (int i = 0; i < ROW; i++)
                matrix[i][0] = 0;
        
        if (firstRow)
            for (int i = 0; i < COL; i++)
                matrix[0][i] = 0;
        
    }
};