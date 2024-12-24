class Solution {
public:
    unordered_map<int, vector<int>> getAdj(vector<vector<int>>& edges){
        unordered_map<int, vector<int>> adj;
        for (vector<int>& i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return adj;
    }

    vector<int> dfs(int curr, int parent, unordered_map<int, vector<int>>& adj){
        int diameter = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(0);
        pq.push(0);
        for (int node: adj[curr]){
            if (node == parent)
                continue;
            vector<int> temp = dfs(node, curr, adj);
            pq.push(temp[1]);
            pq.pop();
            diameter = max(diameter, temp[0]);
        }
        int l = pq.top();
        pq.pop();
        int r = pq.top();
        diameter = max(diameter, l + r);
        vector<int> result;
        result.push_back(diameter);
        result.push_back(1 + (l > r ? l : r));
        return result;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = getAdj(edges1);
        unordered_map<int, vector<int>> adj2 = getAdj(edges2);

        vector<int> d1 = dfs(0, -1, adj1);
        vector<int> d2 = dfs(0, -1, adj2);

        return max(max(d1[0], d2[0]), 1 + (int)ceil(d1[0]/2.0) + (int)ceil(d2[0]/2.0));
    }
};