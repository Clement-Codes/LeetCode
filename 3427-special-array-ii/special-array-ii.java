class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        boolean result[] = new boolean[queries.length];
        int prefix[] = new int[nums.length];
        Arrays.fill(prefix, 0);
        for (int i = 0; i < nums.length - 1; i++)
        {
            prefix[i + 1] = prefix[i];
            if (nums[i] % 2 == nums[i + 1] % 2)
            prefix[i + 1] += 1;
        }
        for (int i = 0; i < queries.length; i++)
            result[i] = prefix[queries[i][1]] - prefix[queries[i][0]] == 0;
        return result;
    }
}