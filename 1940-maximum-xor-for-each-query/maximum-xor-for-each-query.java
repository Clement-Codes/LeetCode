class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int xors = 0;
        for (int i: nums)
            xors ^= i;
        
        int maxi = (1 << maximumBit) - 1;

        int[] result = new int[nums.length];
        int j = 0;
        for (int i = nums.length - 1; i >= 0; i--){
            result[j] = xors ^ maxi;
            xors ^= nums[i];
            j += 1;
        }
        return result;
    }
}