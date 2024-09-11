class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        results = set()
        for i in nums:
            if i not in results:
                results.add(i)
            else:
                return True
        return False
        