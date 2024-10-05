class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        result = max(nums)
        maxv, minv = 1, 1

        for i in nums:
            temp = maxv
            maxv = max(maxv * i, minv * i, i)
            minv = min(temp * i, minv * i, i)
            result = max(result, maxv)
        return result