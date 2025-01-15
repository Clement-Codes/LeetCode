class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        def countBit(n: int) -> int:
            result = 0
            while n > 0:
                if n & 1:
                    result += 1
                n = n >> 1
            return result
        
        count1, count2 = countBit(num1), countBit(num2)
        result = num1
        i = 0
        while count1 > count2:

            if result & (1 << i):
                result = result ^ (1 << i)
                count1 -= 1
            i += 1
        

        while count1 < count2:
            if result & (1 << i) == 0:
                result = result ^ (1 << i)
                count1 += 1
            i += 1

        return result
    