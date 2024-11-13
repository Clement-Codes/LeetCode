class Solution {
    int binary(int l, int r, int target, int[] nums){
        while (l <= r){
            int m = l + (int)((r - l) / 2);
            if (nums[m] >= target) r = m - 1;
            else l = m + 1;
        }
        return r;
    }

    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);

        long result = 0;

        for (int i = 0; i < nums.length - 1; i++){
            int l_target = lower - nums[i];
            int r_target = upper - nums[i] + 1;
            result += (binary(i + 1, nums.length - 1, r_target, nums) - binary(i + 1, nums.length - 1, l_target, nums));
        }
        return result;
    }
}