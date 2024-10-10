class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int t = 0, l = 0, b = matrix.length, r = matrix[0].length;
        List<Integer> result = new ArrayList<Integer>(); 
        while (t < b && l < r){
            for (int i = l; i < r; i++){
                result.add(matrix[t][i]);
            }
            t += 1;

            for (int i = t; i < b; i++){
                result.add(matrix[i][r - 1]);
            }
            r -= 1;

            if(!(t < b && l < r)) break;

            for (int i = r - 1; i >= l; i--){
                result.add(matrix[b - 1][i]);
            }
            b -= 1;

            for (int i = b -1; i >= t; i--){
                result.add(matrix[i][l]);
            }
            l += 1;
        }
        return result;
    }
}