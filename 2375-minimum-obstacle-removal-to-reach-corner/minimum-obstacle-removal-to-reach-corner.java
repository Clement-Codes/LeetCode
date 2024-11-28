class Solution {
    //deque
    public int minimumObstacles(int[][] grid) {
        int ROW = grid.length;
        int COL = grid[0].length;

        Deque<List<Integer>> pq = new LinkedList<>();
        HashSet<String> visited = new HashSet<String>();
        pq.add(new ArrayList<Integer>(Arrays.asList(0,0,0)));
        visited.add(String.valueOf(0) + '_' + String.valueOf(0));
        int directions[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (pq.size() > 0){
            List<Integer> temp = pq.poll();
            if (temp.get(1) == ROW - 1 && temp.get(2) == COL - 1){
                return temp.get(0);
            }
            for (int[] direction: directions){
                int x = temp.get(1) + direction[0];
                int y = temp.get(2) + direction[1];
                String key = String.valueOf(x) + '_' + String.valueOf(y);
                if (0 > x || 0 > y || x == ROW || y == COL || visited.contains(key))
                    continue;

                if (grid[x][y] > 0){
                List<Integer> t = new ArrayList<Integer>(Arrays.asList(1 + temp.get(0), x, y));
                pq.addLast(t);
                }
                else{
                List<Integer> t = new ArrayList<Integer>(Arrays.asList(temp.get(0), x, y));
                pq.addFirst(t);
                }
                
                visited.add(key);
            }
        }
        return 0; 
    }
}
    // priority queue
    // public int minimumObstacles(int[][] grid) {
    //     int ROW = grid.length;
    //     int COL = grid[0].length;

    //     PriorityQueue<List<Integer>> pq = new PriorityQueue<>((x, y) -> Integer.compare(x.get(0),y.get(0)));
    //     HashSet<String> visited = new HashSet<String>();
    //     pq.add(new ArrayList<Integer>(Arrays.asList(0,0,0)));
    //     visited.add(String.valueOf(0) + '_' + String.valueOf(0));
    //     int directions[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    //     while (pq.size() > 0){
    //         List<Integer> temp = pq.poll();
    //         if (temp.get(1) == ROW - 1 && temp.get(2) == COL - 1){
    //             return temp.get(0);
    //         }
    //         for (int[] direction: directions){
    //             int x = temp.get(1) + direction[0];
    //             int y = temp.get(2) + direction[1];
    //             String key = String.valueOf(x) + '_' + String.valueOf(y);
    //             if (0 > x || 0 > y || x == ROW || y == COL || visited.contains(key))
    //                 continue;
    //             List<Integer> t = new ArrayList<Integer>(Arrays.asList(grid[x][y] + temp.get(0), x, y));
    //             pq.add(t);
    //             visited.add(key);
    //         }
    //     }
    //     return 0; 
    // }
//}