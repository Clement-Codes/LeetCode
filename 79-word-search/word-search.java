class Solution {
    public boolean backtracking(int i, int j, char[][] board, String word, int ROW, int COL, int index){
        if (index == word.length()) return true;
        if (0 > i || i >= ROW || 0 > j || j >= COL || board[i][j] != word.charAt(index)) return false;
        
        board[i][j] = '#';
        boolean result = backtracking(i + 1, j, board, word, ROW, COL, index + 1) || backtracking(i - 1, j, board, word, ROW, COL, index + 1) || backtracking(i, j + 1, board, word, ROW, COL, index + 1) || backtracking(i, j - 1, board, word, ROW, COL, index + 1);
        board[i][j] = word.charAt(index);
        return result;


    }

    public boolean exist(char[][] board, String word) {
        int ROW = board.length;
        int COL = board[0].length;
        for (int i = 0; i < ROW; i++){
            for (int j = 0; j < COL; j++){
                if(backtracking(i, j, board, word, ROW, COL, 0)) return true;
            }
        }
        return false;
    }
}