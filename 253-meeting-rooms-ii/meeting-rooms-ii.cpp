class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;
        for (int i = 0; i < intervals.size(); i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int s = 0, e = 0, result = 0, count = 0;
        while (s < intervals.size()){
            if (start[s] < end[e]){
                count += 1;
                s += 1;
            }
            else{
                count -= 1;
                e += 1;
            }
            result = max(result, count);
        }
        return result;
    }
};