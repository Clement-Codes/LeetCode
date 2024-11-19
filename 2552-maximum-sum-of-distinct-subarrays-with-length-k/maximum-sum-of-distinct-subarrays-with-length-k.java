class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        long result = 0;
        int l = 0;
        int n = nums.length;
        long sum = 0;
        HashMap<Integer, Integer> counter = new HashMap<>();
        for (int r = 0; r < n; r++){
            sum += nums[r];
            counter.put(nums[r], counter.containsKey(nums[r]) ? counter.get(nums[r]) + 1: 1);

            if (r - l + 1 > k){
                counter.put(nums[l], counter.get(nums[l]) - 1);
                if (counter.get(nums[l]) == 0)
                    counter.remove(nums[l]);
                sum -= nums[l];
                l += 1;
            }


            if (r - l + 1 == k && counter.size() == k){
                result = Math.max(result, sum);
            }
        }
        return result;
    }
}