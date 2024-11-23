class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int ROW = box.length;
        int COL = box[0].length;
        
        for (int r = 0; r < ROW; r++){
            int i = COL - 1;
            for (int c = COL - 1; c >= 0; c--){
                if (box[r][c] == '#'){
                    char temp = box[r][i];
                    box[r][i] = box[r][c];
                    box[r][c] = temp;
                    i -= 1;
                }
                else if(box[r][c] == '*'){
                    i = c - 1;
                }
            }
        }

        char result[][] = new char[COL][ROW];
        for (int i = 0; i < COL; i++){
            for (int j = ROW - 1; j >=0; j--){
                result[i][ROW - j - 1] = box[j][i];
            }
        }
        return result;
    }
}