class Solution {
public:
    struct compare{
        bool operator()(const vector<int>& a, const vector<int>& b){
            return a[0] > b[0];
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> result;
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        int start = 0;
        int end = INT_MAX;
        int currMax = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i][0], i, 0});
            currMax = max(currMax, nums[i][0]);
        }
        while (pq.size() == nums.size()){
            vector<int> curr = pq.top();
            pq.pop();
            if (end - start > currMax - curr[0]){
                start = curr[0];
                end = currMax;
            }
            if (curr[2] + 1 < nums[curr[1]].size()){
                pq.push({nums[curr[1]][curr[2] + 1], curr[1], curr[2] + 1});
                currMax = max(currMax, nums[curr[1]][curr[2] + 1]);
            } 
        }
        result.push_back(start);
        result.push_back(end);
        return result;
    }
};