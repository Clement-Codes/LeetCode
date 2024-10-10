class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int t = 0, l = 0, b = matrix.size(), r = matrix[0].size();
        vector<int> result;
        while (t < b && l < r){
            for (int i = l; i < r; i++){
                result.push_back(matrix[t][i]);
            }
            t += 1;

            for (int i = t; i < b; i++){
                result.push_back(matrix[i][r - 1]);
            }
            r -= 1;

            if(!(t < b && l < r)) break;

            for (int i = r - 1; i >= l; i--){
                result.push_back(matrix[b - 1][i]);
            }
            b -= 1;

            for (int i = b -1; i >= t; i--){
                result.push_back(matrix[i][l]);
            }
            l += 1;
        }
        return result;
    }
};