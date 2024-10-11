class Solution {
    public int[] countBits(int n) {
        int[] result = new int[n + 1];
        Arrays.fill(result, 0);
        int offset = 1;
        for (int i = 1; i < n + 1; i++){
            if (offset * 2 == i){
                offset = i;
            }
            result[i] = 1 + result[i - offset];
        }
        return result;
    }
}