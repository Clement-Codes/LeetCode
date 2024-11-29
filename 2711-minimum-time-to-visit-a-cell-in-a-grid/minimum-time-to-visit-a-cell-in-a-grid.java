class Solution {
    public int minimumTime(int[][] grid) {
        if (Math.min(grid[0][1], grid[1][0]) > 1)
            return -1;
        int row = grid.length, col = grid[0].length;
        PriorityQueue<List<Integer>> q = new PriorityQueue<>((a, b) -> Integer.compare(a.get(0), b.get(0)));
        HashSet<String> visited = new HashSet<>();
        q.add(new ArrayList<Integer>(Arrays.asList(0, 0, 0)));
        visited.add("0_0");
        int directions[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (q.size() > 0){
            List<Integer> temp = q.poll();
            if (temp.get(1) == row - 1 && temp.get(2) == col - 1)
                return temp.get(0);
            for (int[] direction: directions){
                int x = temp.get(1) + direction[0], y = temp.get(2) + direction[1];
                String key = String.valueOf(x) + '_' + String.valueOf(y);
                if (0 > x || 0 > y || x == row || y == col || visited.contains(key))
                    continue;
                int wait = 0;
                if (Math.abs(grid[x][y] - temp.get(0)) % 2 == 0)
                    wait = 1;
                List<Integer> t = new ArrayList<Integer>(Arrays.asList(Math.max(grid[x][y] + wait, temp.get(0) + 1), x, y));
                visited.add(key);
                q.add(t);
            }
        }

        return -1;
    }
}