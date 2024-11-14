class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        l = 1
        r = max(quantities)
        result = 0
        while l <= r:
            m = l + (r - l) // 2
            s = 0
            for i in quantities:
                s += ceil(i / m)
            if s <= n:
                r = m - 1
                result = m
            else:
                l = m + 1
        return result