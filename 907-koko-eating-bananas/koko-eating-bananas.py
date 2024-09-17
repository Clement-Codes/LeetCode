class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        result = r

        while l <= r:
            m = l + ((r - l) // 2)

            th = 0
            for i in piles:
                th += math.ceil(i/m)
            
            if th <= h:
                r = m - 1
                result = m
            else:
                l = m + 1
            
        
        return result