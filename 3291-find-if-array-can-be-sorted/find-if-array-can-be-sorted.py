class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        def getBit(n):
            temp = 0
            while n:
                temp += n & 1
                n  = n >> 1 
            return temp
        min_curr, max_curr = nums[0], nums[0]
        prev_curr = float(-inf)

        for n in nums:
            if getBit(n) == getBit(min_curr):
                min_curr = min(min_curr, n)
                max_curr = max(max_curr, n)
            else:
                if min_curr < prev_curr:
                    return False
                prev_curr = max_curr
                min_curr, max_curr = n, n
        return False if min_curr < prev_curr else True
        # edge = True
        # for i in range(1, len(nums)):
        #     if nums[i - 1] > nums[i]:
        #         edge = False
        # if edge:
        #     return True

        # cache = defaultdict(list)
        # for i in range(len(nums)):
        #     n = nums[i]
        #     temp = 0
        #     while n:
        #         if n & 1:
        #             temp += 1
        #         n = n >> 1
        #     cache[temp].append(nums[i])
        # print(cache)
        # temp = []
        # for i, j in cache.items():
        #     temp.extend(sorted(j))

        # print(temp)
        # for i in range(1, len(temp)):
        #     if temp[i - 1] > temp[i]:
        #         return False
        # return True
