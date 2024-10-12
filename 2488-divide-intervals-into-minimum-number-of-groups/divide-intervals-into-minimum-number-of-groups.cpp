class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;
        for (vector<int> temp: intervals){
            start.push_back(temp[0]);
            end.push_back(temp[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int count = 0, result = 0, i = 0, j = 0;
        while (i < intervals.size() && j < intervals.size()){
            if (start[i] <= end[j]){
                count += 1;
                i += 1;
            }
            else{
                count -= 1;
                j += 1;
            }
            result = max(result, count);
        }
        return result;
    }
};