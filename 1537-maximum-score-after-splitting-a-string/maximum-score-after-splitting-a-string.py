class Solution:
    def maxScore(self, s: str) -> int:
        l = 0
        r = 0

        for i in s:
            if i == '1':
                r += 1

        result = 0
        for i in s[:-1]:
            if i == '0':
                l += 1 
            else:
                r -= 1
            result = max(result, l + r)

        return result