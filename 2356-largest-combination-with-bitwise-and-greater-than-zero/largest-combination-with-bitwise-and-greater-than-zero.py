class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        res = 0
        for i in range(32):
            count = 0
            for n in candidates:
                count += 1 if (1 << i) & n else 0
            res = max(res, count)
        return res
        # counts = [0] * 32

        # for n in candidates:
        #     i = 0
        #     while n:
        #         counts[i] += n & 1
        #         n = n >> 1
        #         i += 1
        # return max(counts)
            
        