class Solution {
public:
    struct comparator{
        bool operator()(const pair<int,int>& a, const pair<int,int>& b){
            return a.first > b.first;
        }
    };
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, comparator> q;
        map<int, int> cache;
        vector<int> result;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)->bool{return a[0] < b[0];});
        vector<int> tempQueries = vector<int>(queries);
        sort(tempQueries.begin(), tempQueries.end());
        int l = 0;
        for (int i: tempQueries){
            while (l < intervals.size() && intervals[l][0] <= i){
                q.push(pair<int,int>(intervals[l][1] - intervals[l][0] + 1,intervals[l][1]));
                l += 1;
            }
            
            while (q.size()>0 && q.top().second < i){
                q.pop();
            }
            
            cache[i] = q.size() > 0 ? q.top().first : -1; 
        }
        for (int i: queries){
            result.push_back(cache[i]);
        }
        return result;
    }
};