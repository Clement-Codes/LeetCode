class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<pair<int, int>> queries2;
        for (int i = 0; i < queries.size(); i++){
            pair<int, int> temp(queries[i], i);
            queries2.push_back(temp);
        }
        sort(queries2.begin(), queries2.end());
        vector<int> result(queries.size(), 0);
        int j = 0;
        int curr_max = 0;
        for (pair<int, int>i : queries2){
            while (j < items.size() && i.first >= items[j][0]){
                curr_max = max(curr_max, items[j][1]);
                j += 1;
            }
            result[i.second] = curr_max;
        }
        
        
        return result;
    }
};