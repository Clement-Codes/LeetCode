class Solution {
    public int longestSquareStreak(int[] nums) {
        HashSet<Double> nums2 = new HashSet<Double>();
        int result = 0;
        for (int i: nums) nums2.add((double)i);
        for (double i: nums2){
            if (nums2.contains(Math.sqrt(i))) continue;
            int j = 1;
            double temp_i = i;
            while ( Math.pow(i, 2) < 100000 && nums2.contains(i * i)){
                j += 1;
                i *= i;
            } 
            result = Math.max(result, j);
        }
        return result > 1 ? result : -1;
    }

    // Sort
    // public int longestSquareStreak(int[] nums) {
    //     Arrays.sort(nums);
    //     int result = 0;
    //     HashMap<Double, Integer> memo = new HashMap<Double, Integer>();
    //     for (int i: nums){
    //         if(memo.containsKey(Math.sqrt(i))){
    //             memo.put((double)i, memo.get(Math.sqrt(i)) + 1);
    //             result = Math.max(result, memo.get((double)i));
    //         }
    //         else{
    //             memo.put((double)i,1);
    //         }
            
            
    //     }
    //     return result > 1 ? result : -1; 
    // }
}