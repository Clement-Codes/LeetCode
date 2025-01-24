class Solution {
public:

    bool dfs(int i, vector<vector<int>>& graph,unordered_map<int, bool>& safe){
        if (safe.contains(i))
            return safe[i];
        safe[i] = false;
        for (int j: graph[i])
            if (!dfs(j, graph, safe))
                return safe[i];
        safe[i] = true;
        return safe[i];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result;
        unordered_map<int, bool> safe;

        for (int i = 0; i < n; i++)
            if (dfs(i, graph, safe))
                result.push_back(i);
        return result;
    }
};