class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> cache;
        int result = INT_MIN;
        for (vector<int> i: matrix){
            string key = "";
            stringstream s;
            for (int j: i){
                if (i[0] == 1){
                    s << ((j == 1 )? 0: 1);
                }
                else{
                    s << j;
                }
            }
            s >> key;
            if (cache.contains(key))
                cache[key] += 1;
            else
                cache[key] = 1;
            result = max(result, cache[key]);
        }
        return result;
    }
};