from collections import defaultdict

class Solution:
    def getGroup(self, n: int) -> int:
        res = 0
        while n > 0:
            res += n % 10
            n = n // 10
        return res

    def countLargestGroup(self, n: int) -> int:
        res = 0
        groups = defaultdict(int)
        for i in range(1, n + 1):
            g = self.getGroup(i)
            groups[g] += 1
            res = max(res, groups[g])
        n = 0
        for i in groups.values():
            if i == res:
                n += 1
        return n