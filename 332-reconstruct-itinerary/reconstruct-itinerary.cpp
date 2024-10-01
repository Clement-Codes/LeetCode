class Solution {
public:
    void dfs(unordered_map<string, vector<string>>& m, vector<string>& result, string node){
        if (m.contains(node)){
            vector<string> temp = m[node];
            while (temp.size()>0){
                string t = temp[0];
                m[node].erase(m[node].begin());
                dfs(m, result, t);
                temp = m[node];
            }
        }
        result.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> mapper;
        for (vector<string> temp: tickets){
            mapper[temp[0]].push_back(temp[1]);
        }

        for (auto i: mapper){
            sort(mapper[i.first].begin(), mapper[i.first].end());
        }

        vector<string> result;
        dfs(mapper, result, "JFK");

        reverse(result.begin(), result.end());
        return result;
        return result.size() == tickets.size() + 1 ? result : vector<string>(); 

    }
};