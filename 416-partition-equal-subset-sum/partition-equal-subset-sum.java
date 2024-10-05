class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int i: nums)
            sum += i;
        int target = sum / 2;
        if ((sum % 2) == 1) return false;

        HashSet<Integer> mapper = new HashSet<Integer>();
        mapper.add(0);

        for (int i = nums.length - 1; i >= 0; i--){
            HashSet<Integer> temp = new HashSet<Integer>();
            for (int j: mapper){
                if (j + nums[i] == target) return true;
                temp.add(j + nums[i]);
                temp.add(j);
            }
            mapper = temp;
        }
        return false;
    }
}