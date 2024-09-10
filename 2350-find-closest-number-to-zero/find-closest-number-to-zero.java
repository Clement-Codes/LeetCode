class Solution {
    public int findClosestNumber(int[] nums) {
        int minIndex = 0;
        for(int i = 0; i<nums.length; i++){
            if (Math.abs(nums[i]) < Math.abs(nums[minIndex])){
                minIndex = i;
            }
            else if (Math.abs(nums[i]) == Math.abs(nums[minIndex]) && nums[i] > nums[minIndex]){
                minIndex = i;
            }
        }
        return nums[minIndex];
    }
}