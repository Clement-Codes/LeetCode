class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        def is_valid(capability):
            i = 0
            count = 0
            while i < len(nums):
                if nums[i] <= capability:
                    i += 2
                    count += 1
                else: 
                    i += 1
                if count == k:
                    break
            return count == k
        l, r = min(nums), max(nums)
        res = 0
        while l <= r:
            m = (r + l) // 2
            if is_valid(m):
                res = m
                r = m - 1
            else:
                l = m + 1
        return res
