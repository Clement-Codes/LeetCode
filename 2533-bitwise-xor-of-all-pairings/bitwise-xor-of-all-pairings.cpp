class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        if (nums2.size() % 2 == 1)
            for (int i: nums1)
                result ^= i;
        if (nums1.size() % 2 == 1)
            for (int i: nums2)
                result ^= i;
        return result;
    }
};