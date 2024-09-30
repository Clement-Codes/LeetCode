class Solution {
public:
    bool dfs(int i, unordered_set<int>& visited, unordered_set<int>& cycle, vector<int>& result, unordered_map<int, vector<int>>& mapper){
        if (cycle.contains(i)) return false;
        if (visited.contains(i)) return true;
        cycle.insert(i);
        for (int j : mapper[i])
            if ( !dfs(j, visited, cycle, result, mapper)) return false;
        cycle.erase(i);
        visited.insert(i);
        result.push_back(i);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mapper;
        for(vector<int> i: prerequisites){
            mapper[i[0]].push_back(i[1]);
        }
        vector<int> result;
        unordered_set<int> visited;
        unordered_set<int> cycle;
        for(int i = 0; i < numCourses; i++)
            if (!dfs(i, visited, cycle, result, mapper)) return vector<int>();
        return result;
    }
};