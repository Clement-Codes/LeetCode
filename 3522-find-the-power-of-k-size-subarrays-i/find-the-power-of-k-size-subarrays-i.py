class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        l = 0
        c = 1
        result = []
        for r in range(len(nums)):
            if r > 0 and nums[r - 1] + 1 == nums[r]:
                c += 1
            if r - l + 1 > k:
                if nums[l] + 1 == nums[l + 1]:
                    c -= 1
                l += 1
            if r - l + 1 == k:
                result.append(nums[r] if c == k else - 1)
        return result
        # c = k - 1
        # n  = len(nums)
        # l = 0
        # heap = []
        # result = []
        # heapq.heappush(heap, -1 * nums[0])

        # while l + 1 < n:
        #     if nums[l] < nums[l + 1]:
        #         c -= 1
        #         heapq.heappush(heap, -1 * nums[l + 1])
        #     else:
        #         c = k - 1
        #         heap.clear()
        #         heapq.heappush(heap, -1 * nums[l + 1])
        #     if l  + 1>= k - 1:
        #         if c <= 0:
        #             result.append(-1 * heap[0])

        #         else:
        #             result.append(-1)
        #     l += 1
        # return result
