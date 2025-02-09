class Solution {
    public long countBadPairs(int[] nums) {
        HashMap<Integer, Integer> count = new HashMap<Integer, Integer>();
        long goodPairs = 0;
        long totalPairs = 0;
        for (int i = 0; i < nums.length; i++){
            totalPairs += i;
            int index = nums[i] - i;
            goodPairs += count.containsKey(index) ? count.get(index) : 0;
            if (count.containsKey(index))
                count.put(index, count.get(index) + 1);
            else
                count.put(index, 1);
        }

        return totalPairs - goodPairs;  
    }
}