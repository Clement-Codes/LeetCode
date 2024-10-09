class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)->bool{return a[0] < b[0];});
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++){
            int last = result[result.size() -1][1];
            if (last >= intervals[i][0]){
                result[result.size() -1][1] = max(last, intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};