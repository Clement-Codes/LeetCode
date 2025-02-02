class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        curr = 1
        for i in range(1, 2 * n):
            if nums[(i - 1) % n] <= nums[i % n]:
                curr += 1
            else:
                curr = 1
            if curr == n:
                return True
        return n == 1