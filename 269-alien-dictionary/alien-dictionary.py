class Solution:
    def alienOrder(self, words: List[str]) -> str:
        mapper = {l:[] for word in words for l in word}
        for i in range(len(words) - 1):
            word1 = words[i]
            word2 = words[i + 1]
            mid = min(len(word1), len(word2))
            if word1[:mid] == word2[:mid] and len(word1) > len(word2):
                return ""
            for j in range(mid):
                if word1[j] != word2[j]:
                    mapper[word1[j]].append(word2[j])
                    break
        
        result = []
        visited = {}
        def dfs(i):
            if i in visited:
                return visited[i]
            
            visited[i] = True
            for j in mapper[i]:
                if dfs(j):
                    return True
            visited[i] = False
            result.append(i)
        
        for i in mapper:
            if dfs(i):
                return ""
        
        result.reverse()

        return ''.join(result)