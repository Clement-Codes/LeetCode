class Solution {
public:
    struct comparator{
        bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
            return p1.first >= p2.first;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<vector<int>>> mapper;
        for(vector<int> temp: times){
            vector<int> t = {temp[1], temp[2]};
            mapper[temp[0]].push_back(t);
        }
        int t = 0; 
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> q;
        q.push(pair<int, int>(0, k));
        while (q.size()>0){
            pair<int, int> temp = q.top();
            q.pop();
            if (visited.contains(temp.second)) continue;
            cout << temp.first << temp.second<<"\n";
            t = max(t, temp.first);
            visited.insert(temp.second);
            for(auto tt: mapper[temp.second])
                if(!visited.contains(tt[0])) q.push(pair<int, int>(tt[1] + t, tt[0]));
        }
        return visited.size() == n ? t : - 1;
    }
};