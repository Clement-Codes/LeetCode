class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        b = set(banned)
        count = 0 
        for i in range(1, n + 1):
            if i in b:
                continue
            
            maxSum -= i
            if maxSum < 0:
                return count
            
            count += 1
        return count


