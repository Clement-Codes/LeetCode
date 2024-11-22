class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        cache = defaultdict(int)
        for i in matrix:
            if i[0] == 0:
                i = [0 if j else 1 for j in i]
                
            cache[str(i)] += 1
        return max(cache.values())
