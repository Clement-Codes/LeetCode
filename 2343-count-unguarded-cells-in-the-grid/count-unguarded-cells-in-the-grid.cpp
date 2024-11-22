class Solution {
public:
    void mark_guarded(int i, int j, vector<vector<int>>& arr, int m, int n){
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

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        vector<vector<int>> arr(m, vector<int>(n, 0));

        // 0 - Normal, 1 - Wall, 2 - Gaurd, 3 - Guard Sigth
        for (int i = 0; i < walls.size(); i++){
            arr[walls[i][0]][walls[i][1]] = 1;
        }

        for (int i = 0; i < guards.size(); i++){
            arr[guards[i][0]][guards[i][1]] = 2;
        }
        
        // for (int i = 0; i < guards.size(); i++){
        //     mark_guarded(guards[i][0], guards[i][1], arr, m, n);
        // }

        for (int i = 0; i < m; i++)
        {
            bool guard = false;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 2)
                    guard = true;
                else if (arr[i][j] == 1)
                    guard = false;
                if (!arr[i][j] && guard)
                    arr[i][j] = 3;
            }

            guard = false;
            for(int j = n - 1; j > -1; j--){
                if (arr[i][j] == 2)
                    guard = true;
                else if (arr[i][j] == 1)
                    guard = false;
                if (!arr[i][j] && guard)
                    arr[i][j] = 3;
            }

        }

        for (int j = 0; j < n; j++){
            bool guard = false;
            for (int i = 0; i < m; i++){
                if (arr[i][j] == 2)
                    guard = true;
                else if (arr[i][j] == 1)
                    guard = false;
                if (!arr[i][j] && guard)
                    arr[i][j] = 3;
            }


            guard = false;
            for (int i = m - 1; i > -1; i--){
                if (arr[i][j] == 2)
                    guard = true;
                else if (arr[i][j] == 1)
                    guard = false;
                if (!arr[i][j] && guard)
                    arr[i][j] = 3;
            }
        }

        int result = 0;

        for (vector<int> i: arr)
            for (int j: i)
                if (j == 0)
                    result += 1;

        return result;
    }
};