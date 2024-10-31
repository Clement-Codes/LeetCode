class Solution {
    long dfs(int i, int j, List<Integer> robot, List<Integer> factories, long[][] memo){
        if (i == -1) return 0;
        if (j == -1) return 10000000000000L;
        if (memo[i][j] != -1) return memo[i][j];
        long include = Math.abs(factories.get(j) - robot.get(i)) + dfs(i - 1, j - 1, robot, factories, memo);
        long exclude = dfs(i, j - 1, robot, factories, memo);
        memo[i][j] = Math.min(include, exclude);
        return memo[i][j];
    }

    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        Collections.sort(robot);
        Arrays.sort(factory, Comparator.comparingInt(a -> a[0]));
        List<Integer> factories = new ArrayList<Integer>();
        for (int[] temp: factory)
            for (int i = 0; i < temp[1]; i++)
                factories.add(temp[0]);
        long[][] memo = new long[robot.size()][factories.size()];
        for (long[] temp : memo)
            Arrays.fill(temp, -1);
        return dfs(robot.size() - 1, factories.size() - 1, robot, factories, memo);
    }
}