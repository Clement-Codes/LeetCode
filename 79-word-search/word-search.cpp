class Solution {
public:
    bool backtracking(int i, int j, vector<vector<char>>& board, string word, int ROW, int COL, int index){
        if (index == word.length()) return true;
        if (0 > i || i >= ROW || 0 > j || j >= COL || board[i][j] != word[index]) return false;
        
        board[i][j] = '#';
        bool result = backtracking(i + 1, j, board, word, ROW, COL, index + 1) || backtracking(i - 1, j, board, word, ROW, COL, index + 1) || backtracking(i, j + 1, board, word, ROW, COL, index + 1) || backtracking(i, j - 1, board, word, ROW, COL, index + 1);
        board[i][j] = word[index];
        return result;


    }
    bool exist(vector<vector<char>>& board, string word) {
        int ROW = board.size();
        int COL = board[0].size();
        for (int i = 0; i < ROW; i++){
            for (int j = 0; j < COL; j++){
                if(backtracking(i, j, board, word, ROW, COL, 0)) return true;
            }
        }
        return false;
    }
};