class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        for i in s:
            anagram = False
            for j in range(len(t)):
                if i == t[j] and not anagram:
                    anagram = True
                    t = t[0:j] + t[j+1:]
                    break
            if not anagram:
                return False
        if len(t) > 0:
            return False
        return True

