class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int maxSum = 0;
        int maxCarry = 0;
        for (vector<int> event: events){
            while(pq.size() > 0 && pq.top()[0] < event[0]){
                maxCarry = max(maxCarry, pq.top()[1]);
                pq.pop();
            }
            maxSum = max(maxSum, maxCarry + event[2]);
            vector<int> temp;
            temp.push_back(event[1]);
            temp.push_back(event[2]);
            pq.push(temp);
        }
        return maxSum;
    }
};