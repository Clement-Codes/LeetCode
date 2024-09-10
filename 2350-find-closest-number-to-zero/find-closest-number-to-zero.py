import sys
class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return None
        
        min_index = 0
        for index, num in enumerate(nums):
            if abs(num) < abs(nums[min_index]):
                    min_index = index
            elif abs(num) == abs(nums[min_index]):
                if num > nums[min_index]:
                    min_index = index
        
        return nums[min_index]