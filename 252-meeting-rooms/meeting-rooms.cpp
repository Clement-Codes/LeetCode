class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {return a[0] < b[0];});
        for(int i = 1; i < intervals.size(); i++){
            int a = intervals[i - 1][1];
            int b = intervals[i][0];
            if (a>b) return false;
        }
        return true;
    }
};