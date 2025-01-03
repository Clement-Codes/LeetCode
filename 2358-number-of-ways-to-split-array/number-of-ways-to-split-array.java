class Solution {
    public int waysToSplitArray(int[] nums) {
        long s = 0;
        for (int num: nums)
            s += num;
        long l = 0;
        int result = 0;
        for (int i = 0; i < nums.length - 1; i++){
            l += nums[i];
            result += (l >= (s - l)) ? 1 : 0;
        }
        return result;
    }
}