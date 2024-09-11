class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = {}
        for i in range(len(nums)):
            if result.get(nums[i], 0):
                return result[nums[i]] + [i]
            else:
                result[target - nums[i]] = [i] 
