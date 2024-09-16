class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2): return False

        m1 = [0] * 26
        m2 = [0] * 26
        for i in range(len(s1)):
            m1[ord(s1[i]) - ord('a')] += 1
            m2[ord(s2[i]) - ord('a')] += 1

        matches = 0
        for i in range(26):
            if m1[i] == m2[i]: matches += 1

        l = 0

        for i in range(len(s1), len(s2), 1):
            if matches == 26: return True

            m2[ord(s2[i]) - ord('a')] +=1
            if m1[ord(s2[i]) - ord('a')] == m2[ord(s2[i]) - ord('a')]: matches += 1
            elif m1[ord(s2[i]) - ord('a')] + 1 == m2[ord(s2[i]) - ord('a')]: matches -=1

            m2[ord(s2[l]) - ord('a')] -=1
            if m1[ord(s2[l]) - ord('a')] == m2[ord(s2[l]) - ord('a')]: matches += 1
            elif m1[ord(s2[l]) - ord('a')] - 1 == m2[ord(s2[l]) - ord('a')]: matches -=1

            l += 1

            print(i,matches)
        return matches == 26
            