class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        l = 0
        r = 1
        while l < r < len(sentence):
            while l < r < len(sentence) and sentence[r - 1] != " ":
                r += 1
            while  l < r < len(sentence) and  sentence[l + 1] != " ":
                l += 1
            if l < r < len(sentence) and sentence[r] != sentence[l]:
                return False
            r+=1
            l+=1
        return True if sentence[0] == sentence[-1] else False
            

