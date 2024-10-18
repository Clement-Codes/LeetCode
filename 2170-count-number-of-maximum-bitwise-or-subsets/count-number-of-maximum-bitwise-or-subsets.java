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

    public int dfs(int index, int curresult, int[] nums, int max_or){
        if(index == nums.length){
            return curresult == max_or ? 1 : 0;
        }
        return dfs(index + 1, curresult, nums, max_or) + dfs(index + 1, curresult | nums[index], nums, max_or);
    }

    public int countMaxOrSubsets(int[] nums) {
        int max_or = 0;
        for (int i: nums)
            max_or |= i;
        return dfs(0, 0, nums, max_or);
    }
}