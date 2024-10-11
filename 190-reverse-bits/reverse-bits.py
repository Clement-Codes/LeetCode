class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        for i in range(32):
            temp = (n >> i) & 1
            res = res | temp << (31 - i)
        return res