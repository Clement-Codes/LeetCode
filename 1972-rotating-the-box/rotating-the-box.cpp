class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // Using new Array
        int ROW = box.size();
        int COL = box[0].size();
        vector<vector<char>> result(COL, vector<char>(ROW, '.'));
        for (int r = 0; r < ROW; r++){
            int i = COL - 1;
            for (int c = COL - 1; c >= 0; c--){
                if (box[r][c] == '#'){
                    result[i][ROW - r - 1] = '#';
                    i -= 1;
                }
                else if(box[r][c] == '*'){
                    result[c][ROW - r - 1] = '*';
                    i = c - 1;
                }
            }
        }
        return result;

        // Inplace
        // int ROW = box.size();
        // int COL = box[0].size();
        
        // for (int r = 0; r < ROW; r++){
        //     int i = COL - 1;
        //     for (int c = COL - 1; c >= 0; c--){
        //         if (box[r][c] == '#'){
        //             int temp = box[r][i];
        //             box[r][i] = box[r][c];
        //             box[r][c] = temp;
        //             i -= 1;
        //         }
        //         else if(box[r][c] == '*'){
        //             i = c - 1;
        //         }
        //     }
        // }

        // vector<vector<char>> result;
        // for (int i = 0; i < COL; i++){
        //     vector<char> temp;
        //     for (int j = ROW - 1; j >=0; j--){
        //         temp.push_back(box[j][i]);
        //     }
        //     result.push_back(temp);
        // }
        // return result;
    }
};