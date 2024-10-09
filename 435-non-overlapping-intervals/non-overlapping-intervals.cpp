class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)->bool{return a[0]<b[0];});
        int last = intervals[0][1];
        int result = 0;
        for (int i = 1; i < intervals.size(); i++)
            if (last <= intervals[i][0]) last = intervals[i][1];
            else{
                last = min(last, intervals[i][1]);
                result += 1;
            }
        return result;
    }
};