class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0, r = matrix.size() - 1;
        while (l < r){
            
            for (int i = 0; i < r - l; i++){
                int t = l, b = r;
                int temp = matrix[t][l + i];
                matrix[t][l + i] = matrix[b - i][l];
                matrix[b - i][l] = matrix[b][r - i];
                matrix[b][r - i] = matrix[t + i][r];
                matrix[t + i][r] = temp;
            }
            l += 1;
            r -= 1;
        }
    }
};