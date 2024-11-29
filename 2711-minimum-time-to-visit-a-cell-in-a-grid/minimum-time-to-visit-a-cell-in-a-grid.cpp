class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (min(grid[0][1], grid[1][0]) > 1)
            return -1;
        int row = grid.size(), col = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        unordered_set<string> visited;
        q.push(vector<int>(3, 0));
        visited.insert("0_0");
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (q.size() > 0){
            vector<int> temp = q.top();
            q.pop();
            if (temp[1] == row - 1 && temp[2] == col - 1)
                return temp[0];
            for (vector<int> direction: directions){
                int x = temp[1] + direction[0], y = temp[2] + direction[1];
                string key = to_string(x) + '_' + to_string(y);
                if (0 > x || 0 > y || x == row || y == col || visited.contains(key))
                    continue;
                int wait = 0;
                if (abs(grid[x][y] - temp[0]) % 2 == 0)
                    wait = 1;
                vector<int>t = {max(grid[x][y] + wait, temp[0] + 1), x, y};
                visited.insert(key);
                q.push(t);
            }
        }

        return 1;
    }
};