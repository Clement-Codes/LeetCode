class Solution {
    public void wallsAndGates(int[][] rooms) {
        Queue<Pair<Integer,Integer>> q = new LinkedList<Pair<Integer,Integer>>();
        HashSet<String> visited = new HashSet<String>();
        int row = rooms.length;
        int col = rooms[0].length;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if(rooms[i][j] == 0){
                    q.add(new Pair<Integer,Integer>(i,j));
                    visited.add(String.valueOf(i) + ',' + String.valueOf(j));
                }
        int distance = 0;
        while(q.size()>0){
            int len = q.size();
            for (int i = 0; i < len; i++){
                Pair<Integer,Integer> temp = q.poll();
                int r = temp.getKey();
                int c = temp.getValue();
                rooms[r][c] = distance;
                int direction[][] = {{1,0},{0,1},{-1,0},{0,-1}};
                for(int d[]: direction){
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if (nr>=0 && nc>=0 && nr<row && nc<col && rooms[nr][nc] != -1 && !visited.contains(String.valueOf(nr) + ',' + String.valueOf(nc))){
                    q.add(new Pair<Integer,Integer>(nr,nc));
                    visited.add(String.valueOf(nr) + ',' + String.valueOf(nc));
                    }
                }
            }
            distance += 1;
        }
    }
}