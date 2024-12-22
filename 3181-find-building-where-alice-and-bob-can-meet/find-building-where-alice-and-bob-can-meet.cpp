class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n, -1);

        unordered_map<int, vector<vector<int>>> grouped;
        for (int i = 0; i < queries.size(); i++){
            int l = queries[i][0], r = queries[i][1];
            if (l > r){
                int temp = l;
                l = r;
                r = temp;
            }
            if (l == r || heights[l] < heights[r]){
                result[i] = r;
            }
            else{
                grouped[r].push_back({heights[l], i});
            }
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for (int i = 0 ;i < heights.size(); i++){
            for (vector<int> j: grouped[i]){
                pq.push(j);
            }

            while (pq.size() > 0 and heights[i] > pq.top()[0]){
                vector<int> temp = pq.top();
                pq.pop();
                result[temp[1]] = i;
            }
        }
        return result;
    }
};