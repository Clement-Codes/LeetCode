class Solution {
    int row;
    int col;

    void dfs(int r, int c, List<Pair<Integer, Integer>> visited, int prevHeight, int[][] heights){
        if (r < 0 || c < 0 || r == row || c == col || prevHeight > heights[r][c] || visited.contains(new Pair<Integer, Integer>(r, c))) return;
        visited.add(new Pair<Integer, Integer>(r, c));
        dfs(r + 1, c, visited, heights[r][c], heights);
        dfs(r - 1, c, visited, heights[r][c], heights);
        dfs(r, c + 1, visited, heights[r][c], heights);
        dfs(r, c - 1, visited, heights[r][c], heights);
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        row = heights.length;
        col = heights[0].length;
        List<Pair<Integer, Integer>> pac = new ArrayList<Pair<Integer, Integer>>();
        List<Pair<Integer, Integer>> alt = new ArrayList<Pair<Integer, Integer>>();
        List<List<Integer>> result = new ArrayList<List<Integer>>();

        for (int i = 0; i < col; i++){
            dfs(0, i, pac, heights[0][i], heights);
            dfs(row - 1, i, alt, heights[row-1][i], heights);
        }

        for (int i = 0; i < row; i++){
            dfs(i, 0, pac, heights[i][0], heights);
            dfs(i, col - 1, alt, heights[i][col - 1], heights);
        }

        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (pac.contains(new Pair<Integer, Integer>(i,j)) && alt.contains(new Pair<Integer, Integer>(i,j))){
                    result.add(Arrays.asList(i, j));
                }
            }
        }

        return result;
    }
}