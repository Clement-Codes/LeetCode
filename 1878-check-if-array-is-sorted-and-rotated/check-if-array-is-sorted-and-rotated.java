class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        int curr = 1;
        for (int i = 1; i < 2 * n; i++){
            if (nums[(i - 1) % n] <= nums[i % n]){
                curr += 1;
            }else{
                curr = 1;
            }
            if (curr == n)
                return true;
        }
        return n == 1;  
    }
}