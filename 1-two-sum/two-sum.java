import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> prev = new HashMap<Integer, Integer>();
        int[] result = new int[2];
        for(int i = 0; i < nums.length; i++){
            if(prev.get(target - nums[i]) != null){
                result[0] = prev.get(target - nums[i]);
                result[1] = i;
                return result;
            }
            else{
                prev.put(nums[i],i);
            }
        }
        return result; 
    }
}