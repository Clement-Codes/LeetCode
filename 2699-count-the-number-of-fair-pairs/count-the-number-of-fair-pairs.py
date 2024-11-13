class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()

        def binarySearch(l, r, target):
            while l <= r:
                m = l + (r - l)//2
                if nums[m] >= target:
                    r = m - 1
                else:
                    l = m + 1
            return r
        
        result = 0
        for i in range(len(nums)):
            small = lower - nums[i]
            large =  upper + 1 - nums[i]
            result += (binarySearch(i + 1, len(nums) - 1, large) - binarySearch(i + 1, len(nums) - 1, small))
        return result