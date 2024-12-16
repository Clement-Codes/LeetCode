class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});
        while (k > 0){
            vector<int> temp = pq.top();
            pq.pop();
            nums[temp[1]] *= multiplier;
            pq.push({nums[temp[1]], temp[1]});
            k -= 1;
        }
        return nums;
    }
};