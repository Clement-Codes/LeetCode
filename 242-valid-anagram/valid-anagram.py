class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        h_s, h_t = {}, {}
        for i in range(len(s)):
            h_s[s[i]] = 1 + h_s.get(s[i],0)
            h_t[t[i]] = 1 + h_t.get(t[i],0)
        
        for i in h_s.keys():
            if h_s[i] != h_t.get(i, 0):
                return False
        return True
        
        #print(h_s)
        # for i in s:
        #     anagram = False
        #     for j in range(len(t)):
        #         if i == t[j] and not anagram:
        #             anagram = True
        #             t = t[0:j] + t[j+1:]
        #             break
        #     if not anagram:
        #         return False
        # if len(t) > 0:
        #     return False
        # return True

