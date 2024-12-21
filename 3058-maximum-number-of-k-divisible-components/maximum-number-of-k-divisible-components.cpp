class Solution {
public:
    int result = 0;

    long dfs(int curr, int parent, unordered_map<int, vector<int>>& adj, vector<int>& values, int k){
        long total = values[curr];

        for (int node: adj[curr])
            if (node != parent)
                total += dfs(node, curr, adj, values, k);

        if (total % k == 0){
            result += 1;
        }

        return total;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, vector<int>> adj;
        for (vector<int> edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, adj, values, k);
        return result;
    }
};