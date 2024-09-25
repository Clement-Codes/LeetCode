class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = []
        combination = []
        nums.sort()

        def dfs(index):
            if index >= len(nums):
                result.append(combination[::])
                return
            
            combination.append(nums[index])
            dfs(index + 1)

            combination.pop()
            while index + 1 < len(nums) and nums[index] == nums[index + 1]:
                index = index + 1
            dfs(index + 1)
        
        dfs(0)
        return result