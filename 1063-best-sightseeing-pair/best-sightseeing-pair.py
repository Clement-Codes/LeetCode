class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        res = 0
        m = 0
        for i in values:
            res = max(res, m + i)
            m = max(m - 1, i - 1)
        return res