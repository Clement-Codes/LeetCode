class Solution {
    public void backtracking(int index, int[] nums, List<Integer> combination, List<List<Integer>> result)
    {
        if(index >= nums.length){
            result.add(List.copyOf(combination));
            return;
        }

        combination.add(nums[index]);
        backtracking(index + 1, nums, combination, result);

        combination.remove(combination.size() - 1);

        while (index + 1 < nums.length && nums[index] == nums[index+1]) index += 1;
        backtracking(index + 1, nums, combination, result);

    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        // List<Integer> temp = new ArrayList<Integer>();
        // result.add(temp);
        List<Integer> combination = new ArrayList<Integer>();
        backtracking(0, nums, combination, result);
        return result;
    }
}