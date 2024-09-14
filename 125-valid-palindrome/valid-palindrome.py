class Solution:
    def isAlphaNum(self, str):
        if (ord('A') <= ord(str) <= ord('Z')) or (ord('a') <= ord(str) <= ord('z')) or ord('0') <= ord(str) <= ord('9'):
            return True
        return False

    def isPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s) - 1
        while i<j:
            while i<j and not self.isAlphaNum(s[i]):
                i += 1
            while i<j and not self.isAlphaNum(s[j]):
                j -= 1
            if s[i].lower() != s[j].lower():
                return False
            i += 1
            j -= 1
        return True