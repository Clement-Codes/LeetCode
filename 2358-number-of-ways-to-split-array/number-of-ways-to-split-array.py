class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        cache = [0] * (len(nums) + 1)
        for i, num in enumerate(nums):
            cache[i + 1] = num + cache[i]
        s = sum(nums)

        result = 0
        for l in range(0, len(nums) - 1):
            if (cache[l + 1] >= s - cache[l + 1]):
                result += 1
        return result
