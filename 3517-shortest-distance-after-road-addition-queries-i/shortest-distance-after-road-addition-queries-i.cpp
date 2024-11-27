class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n - 1);
        for (int i = 0; i < n - 1; i++)
            adj[i].push_back(i+1);
        
        vector<int> result;
        for (vector<int> query: queries){
            adj[query[0]].push_back(query[1]);
            unordered_set<int> visited;
            queue<pair<int,int>> q;
            q.push(pair<int,int>(0, 0));
            visited.insert(0);
            while (q.size() > 0){
                pair<int,int> temp = q.front();
                q.pop();
                if (temp.first == n - 1)
                {
                    result.push_back(temp.second);
                    break;
                }
                for (int i: adj[temp.first]){
                    if (!visited.contains(i)){
                        q.push(pair<int,int>(i, temp.second + 1));
                        visited.insert(i);
                    }
                }
            }
        }
        return result;
    }
};