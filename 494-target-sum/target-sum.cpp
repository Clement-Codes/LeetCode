class Solution {
public:
    unordered_map<string, int> cache;
    int dfs(int index, int sum, vector<int>& nums, int target){
        if (index == nums.size()) return sum == target ? 1 : 0;
        string key = to_string(index) + "_" + to_string(sum);
        if (cache.contains(key)) return cache[key];
        cache[key] = dfs(index + 1, sum + nums[index], nums, target) + dfs(index + 1, sum - nums[index], nums, target);
        return cache[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, 0, nums, target);
    }
};