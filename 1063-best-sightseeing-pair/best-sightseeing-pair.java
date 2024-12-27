class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int result = 0;
        int m = 0;
        for (int i: values){
            result = Math.max(result, m + i);
            m = Math.max(m - 1, i - 1);
        }
        return result;
    }
}