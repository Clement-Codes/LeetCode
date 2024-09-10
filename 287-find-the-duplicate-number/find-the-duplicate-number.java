import java.util.HashMap;

class Solution {
    public int findDuplicate(int[] nums) {
        HashMap<Integer, Integer> results = new HashMap<Integer, Integer>();
        for(int i: nums){
            if (results.containsKey(i)){
                return i;
            }
            else{
                results.put(i, 1);
            }
        }
        return 0;
    }
} 