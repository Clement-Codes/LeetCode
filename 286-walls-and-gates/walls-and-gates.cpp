class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> q;
        unordered_set<string> visited;
        int row = rooms.size();
        int col = rooms[0].size();
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if(rooms[i][j] == 0){
                    q.push(pair<int,int>(i,j));
                    visited.insert(to_string(i) + ',' + to_string(j));
                }
        int distance = 0;
        while(q.size()>0){
            int len = q.size();
            for (int i = 0; i < len; i++){
                pair<int, int> temp = q.front();
                int r = temp.first;
                int c = temp.second;
                rooms[r][c] = distance;
                q.pop();
                int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
                for(auto d: direction){
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if (nr>=0 && nc>=0 && nr<row && nc<col && rooms[nr][nc] != -1 && !visited.contains(to_string(nr) + ',' + to_string(nc))){
                    q.push(pair<int,int>(nr,nc));
                    visited.insert(to_string(nr) + ',' + to_string(nc));
                    }
                }
            }
            distance += 1;
        }
    }
};