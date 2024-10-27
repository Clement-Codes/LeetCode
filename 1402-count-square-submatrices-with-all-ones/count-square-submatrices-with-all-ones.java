class Solution {
    public int countSquares(int[][] matrix) {
        int ROW = matrix.length, COL = matrix[0].length, result = 0;
        HashMap<String, Integer> memo = new HashMap<String, Integer>();
        for (int r = 0; r < ROW; r++)
            for (int c = 0; c < COL; c++){
                if (r > 0 && c > 0 && matrix[r][c] != 0){
                    memo.put(String.valueOf(r) + "_" + String.valueOf(c), 1 + Math.min(memo.get(String.valueOf(r - 1) + "_" + String.valueOf(c)),
                    Math.min(memo.get(String.valueOf(r) + "_" + String.valueOf(c - 1)), memo.get(String.valueOf(r - 1) + "_" + String.valueOf(c - 1)))));
                    result +=  memo.get(String.valueOf(r) + "_" + String.valueOf(c));
                }
                else{
                    memo.put(String.valueOf(r) + "_" + String.valueOf(c), matrix[r][c]);
                    result += matrix[r][c];
                }             
            }
        return result;
    }
    // dfs
    // int ROW = 0, COL = 0;

    // int dfs(int r, int c, int[][] matrix, HashMap<String, Integer> memo){
    //     String key = String.valueOf(r) + "_" + String.valueOf(c);
    //     if (memo.containsKey(key)) return memo.get(key);
    //     if (r == ROW || c == COL || matrix[r][c] == 0) return 0;
    //     memo.put(key, 1 + Math.min(dfs(r + 1, c, matrix, memo), Math.min(dfs(r, c + 1, matrix, memo), dfs(r + 1, c + 1, matrix, memo))));
    //     return memo.get(key);
    // }

    // public int countSquares(int[][] matrix) {
    //     int result = 0;
    //     ROW = matrix.length;
    //     COL = matrix[0].length;
    //     HashMap<String, Integer> memo = new HashMap<String, Integer>();
    //     for (int r = 0; r < ROW; r++)
    //         for (int c = 0; c < COL; c++)
    //             result += dfs(r, c, matrix, memo);
    //     return result;
    // }
}