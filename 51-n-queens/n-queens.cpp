class Solution {
public:
    void backtracking(int i, unordered_set<int>& col, unordered_set<int>& pos, unordered_set<int>& neg, int n, char** board, vector<vector<string>>& result){
        if(i == n){
            vector<string> t;
            for(int tempi = 0; tempi < n; tempi++ ){
                string tt = "";
                for(int tempj = 0; tempj < n; tempj++ ){
                    tt += board[tempi][tempj];
                }
                t.push_back(tt);

            }
            result.push_back(t);
            return;
        }
        for (int j = 0; j < n; j++){
            if (!col.contains(j) and !pos.contains(i+j) and !neg.contains(i-j)){
                board[i][j] = 'Q';
                col.insert(j);
                pos.insert(i+j);
                neg.insert(i-j);
                backtracking(i+1, col, pos, neg, n, board, result);
                board[i][j] = '.';
                col.erase(j);
                pos.erase(i+j);
                neg.erase(i-j);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        unordered_set<int> col;
        unordered_set<int> pos;
        unordered_set<int> neg;
        char** board = new char*[n];
        for (int i = 0; i < n; i++){
            board[i] = new char[n];
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                board[i][j] = '.';
            }
        }
        backtracking(0, col, pos, neg, n, board, result);
        return result;
    }
};