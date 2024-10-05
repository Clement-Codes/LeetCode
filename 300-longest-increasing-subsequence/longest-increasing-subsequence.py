class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        mapper = [1] * len(nums)
        for i in range(len(nums) - 1, -1, -1):
            for j in range(i, len(nums)):
                if nums[i] < nums[j]:
                    mapper[i] = max(mapper[i], 1 + mapper[j])
        return max(mapper)