class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        result = 0
        
        def dfs(i, curr):
            if i == len(s):
                return 0

            result = 0
            for j in range(i + 1, len(s) + 1):
                if s[i:j] in curr:
                    continue
                
                curr.add(s[i:j])
                result = max(result, 1 + dfs(j, curr))
                curr.remove(s[i:j])
            return result
            
        return dfs(0, set())
