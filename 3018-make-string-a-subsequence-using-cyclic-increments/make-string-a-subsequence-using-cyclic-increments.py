class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        i, j = 0, 0
        while i < len(str1) and j < len(str2):
            if str1[i] == str2[j] or (ord(str1[i]) + 1 - ord('a')) % 26  == ord(str2[j]) - ord('a'):
                j += 1
            i += 1
        if j != len(str2):
            return False
        return True