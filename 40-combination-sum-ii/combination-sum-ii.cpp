class Solution {
public:
    void backtracking(int index, int total, vector<int>& candidates, int target,vector<int>& combination, vector<vector<int>>& result){
        if (total == target){
            result.push_back(combination);
            return;
        }

        if ((total > target) || (index >= candidates.size())) return;

        combination.push_back(candidates[index]);
        backtracking(index + 1, total + candidates[index], candidates, target, combination, result);

        combination.pop_back();
        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) index += 1;
        backtracking(index + 1, total, candidates, target, combination, result);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        backtracking(0, 0, candidates, target, combination, result);
        return result;
    }
};