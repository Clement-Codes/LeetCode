class Solution {
public:
    // Brute Force
    // void dfs(int index, int curresult, vector<int>& nums, int& max_or, int& result){
    //     if (index == nums.size())
    //     {
    //         if(curresult == max_or){
    //             result += 1;
    //         }
    //         return;
    //     }

    //     dfs(index + 1, curresult, nums, max_or, result);
    //     dfs(index + 1, curresult | nums[index], nums, max_or, result);
    // }

    // int countMaxOrSubsets(vector<int>& nums) {
    //     int max_or = 0;
    //     int result = 0;
    //     for(int i: nums)
    //         max_or |= i;
    //     dfs(0, 0, nums, max_or, result);
    //     return result;
    // }

    int dfs(int index, int curresult, vector<int>& nums, int& max_or){
        if (index == nums.size())
        {
            return curresult == max_or ? 1 : 0 ;
        }
        return dfs(index + 1, curresult, nums, max_or) + dfs(index + 1, curresult | nums[index], nums, max_or);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for(int i: nums)
            max_or |= i;
        return dfs(0, 0, nums, max_or);
    }
};