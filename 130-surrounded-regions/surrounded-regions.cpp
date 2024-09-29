class Solution {
public:
    int row;
    int col;

    void dfs(int i, int j, vector<vector<char>>& board){
        if (i < 0 || j < 0 || i == row || j == col || board[i][j] != 'O') return;
        board[i][j] = 'T';
        dfs(i + 1, j, board);
        dfs(i - 1, j, board);
        dfs(i, j + 1, board);
        dfs(i, j - 1, board);
    }

    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col ; j++){
                if(board[i][j]=='O' and (i==0 or i == row-1 or j == 0 or j == col - 1)) dfs(i, j, board);
            }
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col ; j++)
                if(board[i][j] == 'O')
                    board[i][j] = 'X';

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col ; j++)
                if(board[i][j] == 'T')
                    board[i][j] = 'O';

    }
};