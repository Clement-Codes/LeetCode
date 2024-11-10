class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        result = float("inf")
        bits = [0] * 32

        def bitOperation(bits, num, diff):
            for i in range(32):
                if num & (1 << i):
                    bits[i] += diff

        def getInteger(bits):
            temp = 0
            for i in range(32):
                if bits[i] > 0:
                    temp += (1 << i)
            return temp

        l = 0
        

        for r in range(len(nums)):
            bitOperation(bits, nums[r], 1)
            curr = getInteger(bits)
            while curr >= k and l <= r:
                result = min(result, r - l + 1)
                bitOperation(bits, nums[l], -1)
                curr = getInteger(bits)
                l += 1
        return -1 if result == float("inf") else result