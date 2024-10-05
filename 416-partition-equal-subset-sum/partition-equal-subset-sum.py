class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums)%2 == 1: return False

        mapper = set()
        mapper.add(0)
        target = sum(nums)//2
        for i in range(len(nums) - 1, -1, -1):
            temp = set()
            for j in mapper:
                if nums[i] + j == target:
                    return True
                temp.add(nums[i] + j)
                temp.add(j)
            mapper = temp
        return False
