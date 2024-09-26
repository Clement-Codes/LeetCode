class Solution {
    public void backtracking(int i, HashSet<Integer> col, HashSet<Integer> pos, HashSet<Integer> neg, int n, char[][] board, List<List<String>> result){
        if(i == n){
            List<String> t = new ArrayList<String>();
            for(int tempi = 0; tempi < n; tempi++ ){
                String tt = "";
                for(int tempj = 0; tempj < n; tempj++ ){
                    tt += board[tempi][tempj];
                }
                t.add(tt);

            }
            result.add(List.copyOf(t));
            return;
        }
        for (int j = 0; j < n; j++){
            if (!col.contains(j) && !pos.contains(i+j) && !neg.contains(i-j)){
                board[i][j] = 'Q';
                col.add(j);
                pos.add(i+j);
                neg.add(i-j);
                backtracking(i+1, col, pos, neg, n, board, result);
                board[i][j] = '.';
                col.remove(j);
                pos.remove(i+j);
                neg.remove(i-j);
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<List<String>>();
        HashSet<Integer> col = new HashSet<Integer>();
        HashSet<Integer> pos = new HashSet<Integer>();
        HashSet<Integer> neg = new HashSet<Integer>();
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                board[i][j] = '.';
            }
        }
        
        backtracking(0, col, pos, neg, n, board, result);
        return result;        
    }
}