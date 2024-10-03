class Solution {
    public int minCostClimbingStairs(int[] cost) {
        List<Integer> temp = Arrays.stream(cost).boxed().collect(Collectors.toList());

        temp.add(0);
        for (int i = temp.size() -3; i >= 0; i--)
            temp.set(i, temp.get(i) + Math.min(temp.get(i+1), temp.get(i+2)));
        return Math.min(temp.get(0), temp.get(1));
    }
}