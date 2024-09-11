class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = {}
        for i, j in enumerate(nums):
            if (target - j) in result:
                return [result[target - j], i]
            else:
                result[j] = i 
