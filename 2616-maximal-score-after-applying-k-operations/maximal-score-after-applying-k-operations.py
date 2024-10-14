class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        nums = [-i for i in nums]
        heapq.heapify(nums)
        score = 0
        while k:
            top = -1 * heapq.heappop(nums)
            score += top
            heapq.heappush(nums, -1 * ceil(top / 3))
            k -= 1
        return score

