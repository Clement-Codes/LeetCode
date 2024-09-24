class Solution {
public:
    void dfs(int index, vector<int>& candidates, int total, int target, vector<int>& combination, vector<vector<int>>& result){
        if (total == target){
            result.push_back(combination);
            return;
        } 
        if (index >= candidates.size() || total > target) return;

        combination.push_back(candidates[index]);
        dfs(index, candidates, total + candidates[index], target, combination, result);
        combination.pop_back();
        dfs(index + 1, candidates, total, target, combination, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        dfs(0, candidates, 0, target, combination, result);
        return result;
    }
};