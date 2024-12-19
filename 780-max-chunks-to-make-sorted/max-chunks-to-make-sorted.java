class Solution {
    public int maxChunksToSorted(int[] arr) {
        int m = -1;
        int result = 0;
        for (int i = 0; i < arr.length; i++)
        {
            m = Math.max(m, arr[i]);
            if (i == m)
                result++;
        }
        return result;
    }
}