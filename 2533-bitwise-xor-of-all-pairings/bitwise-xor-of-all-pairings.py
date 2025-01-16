class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        result = 0
        if len(nums2) % 2 == 1:
            for i in nums1:
                result ^= i
            
        if len(nums1) % 2 == 1:
            for i in nums2:
                result ^= i

        return result