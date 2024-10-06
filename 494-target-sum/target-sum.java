class Solution {
    HashMap<String, Integer> cache = new HashMap<String, Integer>();
    int dfs(int index, int sum, int[] nums, int target){
        if (index == nums.length) return sum == target ? 1 : 0;
        String key = String.valueOf(index) + "_" + String.valueOf(sum);
        if (cache.containsKey(key)) return cache.get(key);
        cache.put(key,dfs(index + 1, sum + nums[index], nums, target) + dfs(index + 1, sum - nums[index], nums, target));
        return cache.get(key);
    }


    public int findTargetSumWays(int[] nums, int target) {
        return dfs(0, 0, nums, target);
    }
}