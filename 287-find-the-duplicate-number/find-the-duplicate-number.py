class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        results = {}
        for i in nums:
            if i in results:
                return i
            else:
                results[i] = 1
        return False