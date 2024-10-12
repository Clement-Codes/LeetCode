class Solution:
    def reverse(self, x: int) -> int:
        MIN = -2147483648  
        MAX = 2147483647
        result = 0
        while x:
            digit = int(math.fmod(x, 10))
            x = int(x / 10)

            if result > MAX // 10 or (result == MAX // 10 and digit > MAX % 10):
                return 0
            
            if result < MIN // 10 or (result == MIN // 10 and digit < MIN % 10):
                return 0

            result = (result * 10) + digit
        return result