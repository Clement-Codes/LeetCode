class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        def helper(maxBall):
            o = 0
            for i in nums:
                o += ceil(i / maxBall) - 1
                if o > maxOperations:
                    return False
            return True
        
        l = 1
        r = max(nums)
        while l < r:
            m = l + ((r - l) // 2)
            if helper(m):
                r = m
            else:
                l = m + 1
        return r
