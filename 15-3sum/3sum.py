class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()
        for i in range(len(nums)):
            if nums[i] > 0: break
            if i > 0 and nums[i] == nums[i-1]: continue

            j = i + 1
            k = len(nums) - 1

            while j < k:
                if nums[i] + nums[j] + nums[k] > 0: k-=1
                elif nums[i] + nums[j] + nums[k] < 0: j+=1
                else:
                    result.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    while j < k and nums[j] == nums[j-1]:
                        j+=1
        return result
        # result = []
        # nums.sort()
        # for i, j in enumerate(nums):
        #     if j>0:
        #         break
        #     if i > 0 and j == nums[i-1]:
        #         continue
        #     k = i + 1
        #     l = len(nums) - 1
        #     while k < l:
        #         if j + nums[k] + nums[l] > 0:
        #             l -= 1
        #         elif j + nums[k] + nums[l] < 0:
        #             k += 1
        #         else:
        #             result.append([j, nums[k], nums[l]])
        #             k += 1
        #             l -= 1
        #             while k<l and nums[k] == nums[k-1]:
        #                 k += 1
        # return result