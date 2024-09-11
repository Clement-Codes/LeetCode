import java.util.Set;
import java.util.HashSet;

class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> result = new HashSet<Integer>();
        for(int i: nums){
            if(result.contains(i)) return true;
            result.add(i);
        }
        return false;
    }
}