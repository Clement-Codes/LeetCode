class Solution:
    def countSubstrings(self, s: str) -> int:
        result = 0
        for i in range(len(s)):
            l = r = i
            while -1 < l and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
                result += 1
            l = i
            r = i + 1
            while -1 < l and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
                result += 1
        return result