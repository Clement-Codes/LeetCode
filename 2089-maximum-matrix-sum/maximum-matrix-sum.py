class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        total = 0
        neg_count = 0
        mini = float("inf")
        for r in matrix:
            for c in r:
                total += abs(c)
                mini = min(mini, abs(c))
                if c < 0:
                    neg_count += 1
        return total if neg_count % 2 == 0 else total - (mini * 2)
