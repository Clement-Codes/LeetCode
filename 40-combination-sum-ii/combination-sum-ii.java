class Solution {
    public void backtracking(int index, int total, int[] candidates, int target,List<Integer> combination, List<List<Integer>> result){
        if (total == target){
            result.add(List.copyOf(combination));
            return;
        }

        if ((total > target) || (index >= candidates.length)) return;

        combination.add(candidates[index]);
        backtracking(index + 1, total + candidates[index], candidates, target, combination, result);

        combination.remove(combination.size() - 1);
        while (index + 1 < candidates.length && candidates[index] == candidates[index + 1]) index += 1;
        backtracking(index + 1, total, candidates, target, combination, result);

    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> combination = new ArrayList<Integer>();
        Arrays.sort(candidates);
        backtracking(0, 0, candidates, target, combination, result);
        return result;
    }
}