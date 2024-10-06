class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        mapper = [[0 for _ in range(len(text2) + 1)] for _ in range(len(text1) + 1)] 
        for i in range(len(text1) - 1, -1, -1):
            for j in range(len(text2) - 1, -1, -1):
                if text1[i] == text2[j]:
                    mapper[i][j] = 1 + mapper[i+1][j+1]
                else:
                    mapper[i][j] = max(mapper[i+1][j],mapper[i][j+1])
        return mapper[0][0]