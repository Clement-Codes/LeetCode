class Solution:
    def minEnd(self, n: int, x: int) -> int:
        res = x
        i = 1
        j = 1
        while j <= n - 1:
            if i & x == 0:
                if j & (n - 1):
                    res = res | i
                j  = j << 1
            i = i << 1
        return res 

        # kind off brute force
        # result = x
        # for _ in  range(n - 1):
        #     result += 1
        #     result = result | x
        # return result