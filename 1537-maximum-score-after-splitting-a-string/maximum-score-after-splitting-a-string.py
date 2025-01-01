class Solution:
    def maxScore(self, s: str) -> int:
        l = [0, 0]
        r = [0, 0]

        for i in s:
            r[int(i)] += 1

        result = 0
        for i in s[:-1]:
            l[int(i)] += 1 
            r[int(i)] -= 1
            result = max(result, l[0] + r[1])

        return result