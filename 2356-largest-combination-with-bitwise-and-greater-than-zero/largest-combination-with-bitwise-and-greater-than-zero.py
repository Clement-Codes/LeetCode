class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        counts = [0] * 32

        for n in candidates:
            i = 0
            while n:
                counts[i] += n & 1
                n = n >> 1
                i += 1
        return max(counts)
            
        