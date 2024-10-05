class Solution {
    public int lengthOfLIS(int[] nums) {
        int mapper[] = new int[nums.length];
        Arrays.fill(mapper, 1);
        for (int i = nums.length - 1; i >=0 ; i--)
            for (int j = i; j < nums.length; j++)
                if (nums[i] < nums[j]) mapper[i] = Math.max(mapper[i], 1 + mapper[j]);
            
        return Arrays.stream(mapper).max().getAsInt();
    }
}