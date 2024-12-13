class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long result = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> temp;
            temp.push_back(nums[i]);
            temp.push_back(i);
            pq.push(temp);
        }
        vector<bool> visited(nums.size(), false);
        while(pq.size() > 0){
            vector<int> temp = pq.top();
            
            pq.pop();
            
            if (!visited[temp[1]])
            {
            result += temp[0];
            visited[temp[1]] = true;
            if (temp[1] > 0)
                visited[temp[1] - 1] = true;
            if (temp[1] < nums.size() -1)
                visited[temp[1]  + 1] = true;
            }
            
        }
        return result;
    }
};