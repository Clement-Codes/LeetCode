class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        results = set()
        for i in nums:
            if i in results:
                return True
            results.add(i)
        return False
        