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

    //Brute Force without variable
    // int dfs(int index, int curresult, vector<int>& nums, int& max_or){
    //     if (index == nums.size())
    //     {
    //         return curresult == max_or ? 1 : 0 ;
    //     }
    //     return dfs(index + 1, curresult, nums, max_or) + dfs(index + 1, curresult | nums[index], nums, max_or);
    // }

    // int countMaxOrSubsets(vector<int>& nums) {
    //     int max_or = 0;
    //     for(int i: nums)
    //         max_or |= i;
    //     return dfs(0, 0, nums, max_or);
    // }

    // Memoization
    // int dfs(int index, int curresult, vector<int>& nums, int& max_or, unordered_map<string, int> cache){
    //     string key = to_string(index) + "_" + to_string(curresult);
    //     if (cache.contains(key)) return cache[key];
    //     if (index == nums.size())
    //     {
    //         return curresult == max_or ? 1 : 0 ;
    //     }
    //     cache[key] = dfs(index + 1, curresult, nums, max_or, cache) + dfs(index + 1, curresult | nums[index], nums, max_or, cache);
    //     return cache[key];
    // }

    // int countMaxOrSubsets(vector<int>& nums) {
    //     int max_or = 0;
    //     for(int i: nums)
    //         max_or |= i;
    //     unordered_map<string, int> cache;
    //     return dfs(0, 0, nums, max_or, cache);
    // }

    //Bottom Up
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for(int i: nums)
            max_or |= i;
        unordered_map<int, int> cache;
        cache[0] = 1;
        for (int i: nums){
            unordered_map<int, int> temp;
            temp.insert(cache.begin(), cache.end());
            for (pair<int, int> j: cache){
                temp[i | j.first] += j.second;
            }
            cache = temp;
        }
        return cache[max_or];
    }
};