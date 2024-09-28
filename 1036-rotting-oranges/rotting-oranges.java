class Solution {
    public int orangesRotting(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int fresh = 0;
        Queue<Pair<Integer,Integer>> q = new LinkedList<Pair<Integer,Integer>>();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2) q.add(new Pair<Integer,Integer>(i,j));
                if(grid[i][j] == 1) fresh+=1;
            }
        }

            
        int time = 0;
        while(q.size()>0 && fresh>0){
            int l = q.size();
            for(int i = 0; i < l; i++){
                Pair<Integer,Integer> temp= q.poll();
                int direction[][] = {{1,0},{0,1},{-1,0},{0,-1}};
                for(int d[]: direction){
                    int nr = temp.getKey() + d[0];
                    int nc = temp.getValue() + d[1];
                    if (nr<0 || nc<0 || nr==row || nc==col || grid[nr][nc]!=1)continue;
                    grid[nr][nc]=2;
                    fresh-=1;
                    q.add(new Pair<Integer,Integer>(nr,nc));
                }
            }
            time+=1;
        }
        return fresh==0?time:-1;
    }
}