class Solution:
    def minChanges(self, s: str) -> int:
        l, r = 0 , 1
        result = 0
        while r < len(s):
            if s[l] != s[r]:
                print(l, r)
                result += 1
            l = r + 1
            r = l + 1
        return result