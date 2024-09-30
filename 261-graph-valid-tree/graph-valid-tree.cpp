class Solution {
public:
    bool dfs(int i, int prev, unordered_set<int>& visited, unordered_map<int, vector<int>>& mapper){
        if (visited.contains(i)) return false;
        visited.insert(i);
        for(int j: mapper[i]){
            if (j == prev) continue;
            else if (! dfs(j, i, visited, mapper)) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mapper;
        for(vector<int> t: edges){
            mapper[t[0]].push_back(t[1]);
            mapper[t[1]].push_back(t[0]);
        }

        unordered_set<int> visited;

        return dfs(0, -1, visited, mapper) && n == visited.size();
    }
};