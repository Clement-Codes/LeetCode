class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long sum = 0;
        int mini = Integer.MAX_VALUE;
        int neg_count = 0;
        for(int[] r: matrix)
            for(int c: r)
            {
                sum += Math.abs(c);
                mini = Math.min(mini, Math.abs(c));
                if (c < 0)
                    neg_count++;
            }
        return neg_count % 2 == 0 ? sum : sum - (mini * 2); 
    }
}