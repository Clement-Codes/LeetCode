class Solution {
public:
    void backtracking(int index, vector<int>& nums, vector<int>& combination, vector<vector<int>>& result){
        if (index >= nums.size()){
            result.push_back(combination);
            return;
        }
        combination.push_back(nums[index]);
        backtracking(index + 1, nums, combination, result);
        combination.pop_back();
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) index = index + 1;
        backtracking(index + 1, nums, combination, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> combination;

        backtracking(0, nums, combination, result);
        return result;
    }
};