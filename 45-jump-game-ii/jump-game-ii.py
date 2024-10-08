class Solution:
    def jump(self, nums: List[int]) -> int:
        result = 0
        l = r = 0
        while r < len(nums) - 1:
            largest = 0
            for i in range(l, r + 1):
                largest = max(largest, i + nums[i])
            l = r + 1
            r = largest
            result += 1
        return result