class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        xor = 0
        for i in nums:
            xor ^= i
        
        max_num = (1 << maximumBit) - 1

        result = []

        for i in reversed(nums):
            result.append(xor ^ max_num)
            xor ^= i
        return result

        # using reverse
        # max_num = pow(2, maximumBit) - 1
        # for i in range(1, len(nums)):
        #     nums[i] ^= nums[i - 1]
        
        # for i in range(len(nums)):
        #     nums[i] ^= max_num
        # nums.reverse()
        # return nums


        # for i in range(len(nums)):
        #     temp = nums[0]
        #     for j in range(1, len(nums) - i):
        #         temp ^= nums[j]
        #     answer.append(temp)
        # print(answer)
        # return answer