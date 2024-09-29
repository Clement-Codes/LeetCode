class Solution {
public:
    unordered_map<int, vector<int>> mapper;
    unordered_set<int> visited;

    bool dfs(int i){
        if (visited.contains(i)) return false;
        if (mapper[i].size() == 0) return true;
        visited.insert(i);
        for(int j: mapper[i])
            if (!dfs(j)) return false;
        visited.erase(i);
        mapper[i].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(vector<int>i: prerequisites)
            mapper[i[0]].push_back(i[1]);
        
        for(int i = 0; i < numCourses; i++)
            if (!dfs(i)) return false;

        return true;
    }
};