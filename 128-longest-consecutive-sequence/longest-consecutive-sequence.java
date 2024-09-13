import java.util.HashSet;
import java.util.Set;

class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> numsSet = new HashSet<Integer>();
        int result = 0;
        for(int num: nums){
            numsSet.add(num);
        }
        for(int num: numsSet){
            if(!numsSet.contains(num - 1)){
                int length = 1;
                while(numsSet.contains(num + length)) length += 1;
                result = Math.max(length, result);
            }
        }
        return result;
    }
}