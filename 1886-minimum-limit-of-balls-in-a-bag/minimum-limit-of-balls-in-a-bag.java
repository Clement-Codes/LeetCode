class Solution {
    public boolean helper(int[] nums, int maxOperations, int ball){
        int o = 0;
        for (int i: nums){
            o += Math.ceil(i / (ball * 1.0)) -1;
            if (o > maxOperations)
                return false;
        }
        return true;
    }

    public int minimumSize(int[] nums, int maxOperations) {
        int l = 0;
        int r = Arrays.stream(nums).max().getAsInt();
        while (l < r){
            int m = l + (int)Math.floor((r - l) / 2);
            if (helper(nums, maxOperations, m)){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        return r;
    }
}