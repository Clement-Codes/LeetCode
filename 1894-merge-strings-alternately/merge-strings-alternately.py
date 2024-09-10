class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        word = ''
        for i in range(len(word1) + len(word2)):
            if i//2>=len(word1):
                word += word2[i-len(word1)]
            elif i//2>=len(word2):
                word += word1[i-len(word2)]
            elif i//2<len(word1) and i%2==0:
                word += word1[i//2]
            elif i//2<len(word2) and i%2==1:
                word += word2[i//2]
        return word
