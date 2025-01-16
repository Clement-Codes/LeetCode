class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int result = 0;
        if (nums2.length % 2 == 1)
            for (int i: nums1)
                result ^= i;
        if (nums1.length % 2 == 1)
            for (int i: nums2)
                result ^= i;
        return result;
    }
}