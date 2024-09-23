class Solution:
    # def quickSelect(self, l, r, k, nums):
    #     pivot, p = nums[r], l
    #     for i in range(l, r):
    #         if nums[i] <= pivot:
    #             nums[i], nums[p] = nums[p], nums[i]
    #             p += 1
    #     nums[r], nums[p] = nums[p], nums[r]
    #     if p > k:
    #         return self.quickSelect(l, p - 1, k, nums)
    #     elif p < k:
    #         return self.quickSelect(p + 1, r, k, nums)
    #     else:
    #         return nums[p]

    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums = [-n for n in nums]
        heapq.heapify(nums)
        n = 1
        while(n < k):
            heapq.heappop(nums)
            n += 1
        return -nums[0]

        # k = len(nums) - k
        # return self.quickSelect(0, len(nums) - 1, k, nums)
        