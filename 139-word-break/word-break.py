class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        mapper = [False] * (len(s) + 1)
        mapper[len(s)] = True
        for i in range(len(s) - 1, -1, -1):
            for word in wordDict:
                if i + len(word) <= len(s) and s[i:i+len(word)] == word:
                    mapper[i] = mapper[i+len(word)]
                if mapper[i]:
                    break
        return mapper[0]