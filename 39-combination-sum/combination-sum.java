class Solution {
    public void dfs(int index, int[] candidates, int total, int target, List<Integer> combination, List<List<Integer>> result){
        if (total == target){
            result.add(List.copyOf(combination));
            return;
        }
        if (index >= candidates.length || total > target) return;
        combination.add(candidates[index]);
        dfs(index, candidates, total + candidates[index], target, combination, result);
        combination.remove(combination.size() - 1);
        dfs(index + 1, candidates, total, target, combination, result);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<List<Integer>>(); 
        List<Integer> combination = new ArrayList<Integer>();
        dfs(0, candidates, 0, target, combination, result);
        return result;
    }
}