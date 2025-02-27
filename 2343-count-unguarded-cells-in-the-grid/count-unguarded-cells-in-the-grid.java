class Solution {
    public void mark_guarded(int i, int j, int[][] arr, int m, int n){
        for (int t = i - 1; t >= 0; t--){
            if (arr[t][j] == 1 || arr[t][j] == 2)
                break;
            arr[t][j] = 3;
        }
        for (int t = i + 1; t < m; t++){
            if (arr[t][j] == 1 || arr[t][j] == 2)
                break;
            arr[t][j] = 3;
        }
        for (int t = j - 1; t >= 0; t--){
            if (arr[i][t] == 1 || arr[i][t] == 2)
                break;
            arr[i][t] = 3;
        }
        for (int t = j + 1; t < n; t++){
            if (arr[i][t] == 1 || arr[i][t] == 2)
                break;
            arr[i][t] = 3;
        }
    }

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {

        int arr[][] = new int[m][n];
        for (int[] temp: arr)
            Arrays.fill(temp, 0);

        // 0 - Normal, 1 - Wall, 2 - Gaurd, 3 - Guard Sigth
        for (int i = 0; i < walls.length; i++){
            arr[walls[i][0]][walls[i][1]] = 1;
        }

        for (int i = 0; i < guards.length; i++){
            arr[guards[i][0]][guards[i][1]] = 2;
        }
        
        for (int i = 0; i < guards.length; i++){
            mark_guarded(guards[i][0], guards[i][1], arr, m, n);
        }


        int result = 0;

        for (int[] i: arr)
            for (int j: i)
                if (j == 0)
                    result += 1;

        return result;
    }
}