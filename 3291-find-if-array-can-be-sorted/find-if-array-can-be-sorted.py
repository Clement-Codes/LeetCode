class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        #0(n2) using bubble sort
        def getBit(n):
            temp = 0
            while n:
                temp += n & 1
                n  = n >> 1 
            return temp
        
        si, sj = 0, 0 
        for i in range(len(nums)):
            swap = False
            for j in range(len(nums) - i - 1):
                if nums[j] < nums[j + 1]:
                    continue
                if getBit(nums[j]) == getBit(nums[j + 1]):
                    swap = True
                    nums[j], nums[j + 1] = nums[j + 1], nums[j]
                else:
                    return False
            if not swap:
                break
        return True 



        #0(n)
        # def getBit(n):
        #     temp = 0
        #     while n:
        #         temp += n & 1
        #         n  = n >> 1 
        #     return temp
        # min_curr, max_curr = nums[0], nums[0]
        # prev_curr = float(-inf)

        # for n in nums:
        #     if getBit(n) == getBit(min_curr):
        #         min_curr = min(min_curr, n)
        #         max_curr = max(max_curr, n)
        #     else:
        #         if min_curr < prev_curr:
        #             return False
        #         prev_curr = max_curr
        #         min_curr, max_curr = n, n
        # return False if min_curr < prev_curr else True

