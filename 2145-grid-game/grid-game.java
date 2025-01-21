class Solution {
    public long gridGame(int[][] grid) {
        int n = grid[0].length;
        List<Long> prefix_1 = new ArrayList<Long>();
        List<Long> prefix_2 = new ArrayList<Long>();

        for (int i: grid[0])
            prefix_1.add((long) i);

        for (int i: grid[1])
            prefix_2.add((long) i);

        for (int i = 1; i < n; i++){
            prefix_1.set(i, prefix_1.get(i) + prefix_1.get(i-1));
            prefix_2.set(i, prefix_2.get(i) + prefix_2.get(i-1));
        }

        long result = Long.MAX_VALUE;
        for (int i = 0; i < n; i++){
            long top = prefix_1.get(n - 1) - prefix_1.get(i);
            long bottom = i > 0 ? prefix_2.get(i - 1) : 0;
            long second = Math.max(top, bottom);
            result = Math.min(result, second);
        }
        return result;
    }
}