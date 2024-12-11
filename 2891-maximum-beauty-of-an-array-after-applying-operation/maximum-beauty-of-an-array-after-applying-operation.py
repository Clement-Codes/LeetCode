class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        nums.sort()
        l = 0
        result = 0
        for r in range(len(nums)):
            while nums[r] - nums[l] > 2 * k:
                l += 1
            result = max(result, r - l + 1)
        return result