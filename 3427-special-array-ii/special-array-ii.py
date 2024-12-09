class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        def evenOrOdd(n):
            return True if n % 2 == 0 else False
        N = len(nums)
        prefix = [0] * N
        for i in range(N - 1):
            if evenOrOdd(nums[i]) == evenOrOdd(nums[i + 1]):
                prefix[i+1] = prefix[i] + 1
            else:
                prefix[i + 1] = prefix[i]
        result = []
        for query in queries:
            if prefix[query[1]] - prefix[query[0]] == 0:
                result.append(True)
            else:
                result.append(False)
        return result
        # result = []
        # for query in queries:
        #     l = query[0]
        #     r = query[1]
        #     # parity = True
        #     # while l < r:
        #     #     if nums2[l] == nums2[l + 1]:
        #     #         parity = False
        #     #         break
        #     #     l += 1
        #     # result.append(parity)
        #     parity = True
        #     switcher = not nums2[l]
        #     if evenOrOdd(r - l):
        #         while l <= r:
        #             if nums2[l] != nums2[r] or nums2[l] == switcher:
        #                 parity = False
        #                 break
        #             switcher = nums2[l]
        #             l += 1
        #             r -= 1
        #         result.append(parity)
        #     else:
        #         while l < r:
        #             if nums2[l] == nums2[r] or nums2[l] == switcher:
        #                 parity = False
        #                 break
        #             switcher = nums2[l]
        #             l+=1
        #             r-=1
        #         result.append(parity)

        # return result
