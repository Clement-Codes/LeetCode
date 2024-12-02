class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split(' ')
        for i in range(len(words)):
            for j in range(len(words[i])):
                if words[i][j] != searchWord[j]:
                    break
                if j == len(searchWord) -1 :
                    return i + 1
        return -1
            
        
