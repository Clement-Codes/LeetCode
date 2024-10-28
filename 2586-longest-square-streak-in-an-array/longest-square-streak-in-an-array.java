class Solution {
    public int longestSquareStreak(int[] nums) {
        Arrays.sort(nums);
        int result = 0;
        HashMap<Double, Integer> memo = new HashMap<Double, Integer>();
        for (int i: nums){
            if(memo.containsKey(Math.sqrt(i))){
                memo.put((double)i, memo.get(Math.sqrt(i)) + 1);
                result = Math.max(result, memo.get((double)i));
            }
            else{
                memo.put((double)i,1);
            }
            
            
        }
        return result > 1 ? result : -1; 
    }
}