class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        HashSet<Integer> b = new HashSet<Integer>();
        for (int i: banned)
            b.add(i);
        int count = 0;
        for (int i = 1; i < n + 1; i++){
            if (b.contains(i))
                continue;
            maxSum -= i;
            if (maxSum < 0)
                return count;
            count += 1;
        }
        return count;
    }
}