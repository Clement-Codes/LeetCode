import java.util.Collections;
class Solution {
        boolean is_valid(int capacity, int[] nums, int k){
        int i = 0;
        int count = 0;
        while (i < nums.length){
            if (nums[i] <= capacity){
                i += 2;
                count += 1;
            }
            else{
                i += 1;
            }
            if (count == k)
                break;
        }
        return count == k ? true : false;
    }
    public int minCapability(int[] nums, int k) {
        int l = IntStream.of(nums).min().getAsInt(), r = IntStream.of(nums).max().getAsInt();
        int result = 0;
        while (l <= r){
            int m = (l + r) / 2;
            if (is_valid(m, nums, k)){
                result = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return result;   
    }
}