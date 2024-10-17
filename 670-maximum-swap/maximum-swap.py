class Solution:
    def maximumSwap(self, num: int) -> int:
        num = list(str(num))
        max_v = max_i = i = j = -1
        for ii in range(len(num) - 1, -1, -1):
            if int(num[ii]) > max_v:
                max_v = int(num[ii])
                max_i = ii
            if int(num[ii]) < max_v:
                i = ii
                j = max_i
        num[i], num[j] = num[j], num[i]
        return int(''.join(num))