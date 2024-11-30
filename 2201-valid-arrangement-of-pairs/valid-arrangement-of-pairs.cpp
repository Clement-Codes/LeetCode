class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjMatrix;
        unordered_map<int, int> inDegree;
        unordered_map<int, int> outDegree;
        vector<vector<int>> pairedResult;
        vector<int> result;
        for (vector<int>& pair: pairs)
        {
            adjMatrix[pair[0]].push_back(pair[1]);
            inDegree[pair[1]] = (inDegree.contains(pair[1]) ?  inDegree[pair[1]] : 0) + 1;
            outDegree[pair[0]] = (outDegree.contains(pair[0]) ?  outDegree[pair[0]] : 0) + 1;
        }
        int startNode = -1;
        for (auto const & i: outDegree)
            if (outDegree[i.first] == inDegree[i.first] + 1){
                startNode = i.first;
                break;
            }
        
        if (startNode == -1)
            startNode = pairs[0][0];

        deque<int> s;
        s.push_back(startNode);
        while (s.size() > 0){
            int node = s.back();
            if (adjMatrix[node].size() > 0){
                s.push_back(adjMatrix[node][0]);
                adjMatrix[node].erase(adjMatrix[node].begin());
            }
            else{
                result.push_back(node);
                s.pop_back();
            }
        }
        reverse(result.begin(), result.end());
        for (int i = 1; i < result.size(); i++)
        {
            vector<int> temp = {result[i - 1], result[i]};
            pairedResult.push_back(temp);
        }

        return pairedResult;
    }
};