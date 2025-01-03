class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        s = sum(nums)
        result = 0
        l = 0
        for i in range(0, len(nums) - 1):
            l += nums[i] 
            result += 1 if l >= s - l else 0
        return result
