class Solution:
    def isHappy(self, n: int) -> bool:
        cache = set()
        while n not in cache:
            cache.add(n)
            n = self.sumOfSquares(n)
            if n == 1:
                return True

        return False

    def sumOfSquares(self, n):
        result = 0
        while n:
            result += (n % 10) ** 2
            n = n//10
        return result