class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        result = 0
        
        def dfs(i, curr):
            nonlocal result
            if i == len(s):
                
                result = max(result, len(curr))
                return 
            for j in range(i + 1, len(s) + 1):
                if s[i:j] in curr:
                    continue
                temp = set(curr)
                temp.add(s[i:j])
                dfs(j, temp)

        dfs(0, set())
        return result
