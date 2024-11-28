class Solution {

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();

        deque<vector<int>> q;
        unordered_set<string> visited;
        q.push_back(vector<int>(3, 0));
        visited.insert(to_string(0) + '_' + to_string(0));
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (q.size() > 0){
            vector<int> temp = q.front();
            q.pop_front();
            if (temp[1] == ROW - 1 && temp[2] == COL - 1){
                return temp[0];
            }
            for (vector<int>& direction: directions){
                int x = temp[1] + direction[0];
                int y = temp[2] + direction[1];
                string key = to_string(x) + '_' + to_string(y);
                if (0 > x || 0 > y || x == ROW || y == COL || visited.contains(key))
                    continue;
                
                if (grid[x][y] > 0){
                    vector<int> t = {1 + temp[0], x, y};
                    q.push_back(t);
                }
                else{
                    vector<int> t = {temp[0], x, y};
                    q.push_front(t);
                }
                visited.insert(key);
            }
        }
        return 0; 
    }
    // heap
    // struct Compare{
    //     bool operator()(vector<int>& v1, vector<int>& v2){
    //         return v1 > v2;
    //     }
    // };
    // int minimumObstacles(vector<vector<int>>& grid) {
    //     int ROW = grid.size();
    //     int COL = grid[0].size();

    //     priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    //     unordered_set<string> visited;
    //     pq.push(vector<int>(3, 0));
    //     visited.insert(to_string(0) + '_' + to_string(0));
    //     vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    //     while (pq.size() > 0){
    //         vector<int> temp = pq.top();
    //         pq.pop();
    //         if (temp[1] == ROW - 1 && temp[2] == COL - 1){
    //             return temp[0];
    //         }
    //         for (vector<int> direction: directions){
    //             int x = temp[1] + direction[0];
    //             int y = temp[2] + direction[1];
    //             string key = to_string(x) + '_' + to_string(y);
    //             if (0 > x || 0 > y || x == ROW || y == COL || visited.contains(key))
    //                 continue;
    //             vector<int> t = {grid[x][y] + temp[0], x, y};
    //             pq.push(t);
    //             visited.insert(key);
    //         }
    //     }
    //     return 0; 
    // }
};