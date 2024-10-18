class Solution {
    // Brute Force
    // int result = 0;
    // public void dfs(int index, int curresult, int[] nums, int max_or){
    //     if(index == nums.length){
    //         if(curresult == max_or){
    //             result += 1;
    //         }
    //         return;
    //     }
    //     dfs(index + 1, curresult, nums, max_or);
    //     dfs(index + 1, curresult | nums[index], nums, max_or);
    // }

    // public int countMaxOrSubsets(int[] nums) {
    //     int max_or = 0;
    //     for (int i: nums)
    //         max_or |= i;
        
    //     dfs(0, 0, nums, max_or);
    //     return result;
    // }

    // Brute Force without variable
    // public int dfs(int index, int curresult, int[] nums, int max_or){
    //     if(index == nums.length){
    //         return curresult == max_or ? 1 : 0;
    //     }
    //     return dfs(index + 1, curresult, nums, max_or) + dfs(index + 1, curresult | nums[index], nums, max_or);
    // }

    // public int countMaxOrSubsets(int[] nums) {
    //     int max_or = 0;
    //     for (int i: nums)
    //         max_or |= i;
    //     return dfs(0, 0, nums, max_or);
    // }

    //Memoization
    // public int dfs(int index, int curresult, int[] nums, int max_or, HashMap<String, Integer> cache){
    //     String key = String.valueOf(index) + "_" + String.valueOf(curresult);
    //     if(cache.containsKey(key)) return cache.get(key);
    //     if(index == nums.length) return curresult == max_or ? 1 : 0;
        
    //     cache.put(key,  dfs(index + 1, curresult, nums, max_or, cache) + dfs(index + 1, curresult | nums[index], nums, max_or, cache));
    //     return cache.get(key);
    // }

    // public int countMaxOrSubsets(int[] nums) {
    //     HashMap<String, Integer> cache = new HashMap<String, Integer>();
    //     int max_or = 0;
    //     for (int i: nums)
    //         max_or |= i;
    //     return dfs(0, 0, nums, max_or, cache);
    // }

    //Bottom up
    public int countMaxOrSubsets(int[] nums) {
        int max_or = 0;
        for (int i: nums)
            max_or |= i;
        HashMap<Integer, Integer> cache = new HashMap<Integer, Integer>();
        cache.put(0, 1);
        for(int num: nums){
            HashMap<Integer, Integer> temp = new HashMap<Integer, Integer>(cache);
            for(Map.Entry<Integer, Integer> j: cache.entrySet()){
                temp.put(num | j.getKey(), temp.getOrDefault(num | j.getKey(), 0) + j.getValue());
            }
            cache = temp;
        }
        return cache.get(max_or);
    }
}