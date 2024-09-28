class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cout<<grid[i][j];
                if(grid[i][j] == 2) q.push(pair<int,int>(i,j));
                if(grid[i][j] == 1) fresh+=1;
            }
        }

            
        int time = 0;
        while(q.size()>0 && fresh>0){
            int l = q.size();
            for(int i = 0; i < l; i++){
                pair<int,int> temp = q.front();
                q.pop();
                int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
                for(auto d: direction){
                    int nr = temp.first + d[0];
                    int nc = temp.second + d[1];
                    if (nr<0 || nc<0 || nr==row || nc==col || grid[nr][nc]!=1)continue;
                    grid[nr][nc]=2;
                    fresh-=1;
                    q.push(pair<int,int>(nr,nc));
                }
            }
            time+=1;
        }
        return fresh==0?time:-1;
    }
};