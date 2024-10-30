class Solution {
    public int minimumMountainRemovals(int[] nums) {
        int n = nums.length;
        int pre[] = new int[n];
        int pos[] = new int[n];
        Arrays.fill(pre, 1);
        Arrays.fill(pos, 1);

        for (int i = 0; i < n ; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    pre[i] = Math.max(pre[i], 1 + pre[j]);

        for (int i = n - 1; i >= 0 ; i--)
            for (int j = i + 1; j < n; j++)
                if (nums[i] > nums[j])
                    pos[i] = Math.max(pos[i], 1 + pos[j]);
        
        int result = n;
        for (int i = 0; i < n; i++)
            if (Math.min(pos[i], pre[i]) != 1)
                result = Math.min(result, n - pos[i] - pre[i] + 1);
                
        return result;
    }
}