class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        count = defaultdict(int)
        goodPairs = 0
        totalPairs = 0
        for i in range(len(nums)):
            totalPairs += i
            goodPairs += count[nums[i] - i]
            count[nums[i] - i] += 1

        return totalPairs - goodPairs