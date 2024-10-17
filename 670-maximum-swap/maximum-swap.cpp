class Solution {
public:
    int maximumSwap(int num) {
        string temp = to_string(num);
        char max_v = '0';
        int max_i = temp.length() - 1, i = temp.length() - 1, j = temp.length() - 1;
        for (int ii = temp.length() - 1; ii >= 0; ii--){
            if (max_v < temp[ii]){
                max_v = temp[ii];
                max_i = ii;
            }
            if (max_v > temp[ii]){
                i = ii;
                j = max_i;
            }
        }
        char t = temp[i];
        temp[i] = temp[j];
        temp[j] = t;
        return stoi(temp);
    }
};