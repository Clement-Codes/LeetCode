class Solution {
    HashMap<String, Integer> cache = new HashMap<String, Integer>();
    int row = 0;
    int col = 0;
    
    int dfs(int i, int j, int prevValue, int[][] matrix){
        if (i < 0 || j < 0 || i == row || j == col || matrix[i][j] <= prevValue) return 0;
        String key = String.valueOf(i) + "_" + String.valueOf(j);
        if (cache.containsKey(key)) return cache.get(key);
        int res = 1;
        res = Math.max(res, 1 + dfs(i + 1, j, matrix[i][j], matrix));
        res = Math.max(res, 1 + dfs(i - 1, j, matrix[i][j], matrix));
        res = Math.max(res, 1 + dfs(i, j + 1, matrix[i][j], matrix));
        res = Math.max(res, 1 + dfs(i, j - 1, matrix[i][j], matrix));
        cache.put(key,res);
        return res;
    }

    public int longestIncreasingPath(int[][] matrix) {
        row = matrix.length;
        col = matrix[0].length;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                dfs(i, j, -1, matrix);
        return Collections.max(cache.entrySet(), Map.Entry.comparingByValue()).getValue();  
    }
}