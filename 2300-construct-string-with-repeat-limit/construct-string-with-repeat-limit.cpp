class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<int, int> cache;
        priority_queue<vector<int>, vector<vector<int>>, less<vector<int>>> pq;

        for (char& c: s)
            cache[c] = 1 + (cache.contains(c) ? cache[c] : 0);
        
        
        for (auto &temp: cache)
            pq.push({temp.first, temp.second});

        stringstream ss;
        while (pq.size() > 0){
            vector<int> curr = pq.top();
            pq.pop();
            for(int i = 0; i < min(curr[1], repeatLimit); i++)
                ss << (char)curr[0];
            if (curr[1] - repeatLimit  > 0 && pq.size() > 0){
                vector<int> next = pq.top();
                pq.pop();
                ss << (char)next[0];
                if (next[1] > 1)
                    pq.push({next[0], next[1] - 1});
                pq.push({curr[0], curr[1] - repeatLimit});
            }
            
        }
        return ss.str();
    }
};