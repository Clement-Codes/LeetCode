class Solution:
    def longestPalindrome(self, s: str) -> str:
        result = ""
        resultLen = 0
        for i in range(len(s)):
            l = i
            r = i
            while 0 <= l and r < len(s) and s[l] == s[r]:
                if ((r+1)-l) >= resultLen:
                    result = s[l:r+1]
                    resultLen = (r+1)-l
                l -= 1
                r += 1
            l = i
            r = i + 1
            while 0 <= l and r < len(s) and s[l] == s[r]:
                if ((r+1)-l) >= resultLen:
                    print(s[l:r+1])
                    result = s[l:r+1]
                    resultLen = (r+1)-l
                l -= 1
                r += 1
        return result