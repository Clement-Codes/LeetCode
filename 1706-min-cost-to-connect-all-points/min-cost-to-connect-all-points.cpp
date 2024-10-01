class Solution {
public:
    struct comparator{
        bool operator()(const pair<int, int>& t1, const pair<int, int>& t2){
            return t1.first >= t2.first;
        }
    };


    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<vector<int>>> mapper;
        for (int i = 0; i < points.size(); i++){
            vector<int> a = points[i];
            for (int j = i; j < points.size(); j++){
                vector<int> b = points[j];
                vector<int> temp = {abs(a[0] - b[0]) + abs(a[1] - b[1]), j};
                mapper[i].push_back(temp); 
                temp = {abs(a[0] - b[0]) + abs(a[1] - b[1]), i};
                mapper[j].push_back(temp);
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> q;
        q.push(pair<int, int>(0,0));
        unordered_set<int> visited;
        int result = 0;
        while (visited.size() < points.size()){
            pair<int, int> temp = q.top();
            q.pop();
            if(visited.contains(temp.second)) continue;
            result += temp.first;
            visited.insert(temp.second);
            for (vector<int> t: mapper[temp.second])
                if (!visited.contains(t[1])) q.push(pair<int, int>(t[0],t[1]));
        }
        return result;
    }
};