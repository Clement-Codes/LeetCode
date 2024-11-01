class Solution:
    def makeFancyString(self, s: str) -> str:
        result = []
        for i in s:
            if len(result) > 1 and result[-1] == result[-2] == i:
                continue
            result.append(i)
        return ''.join(result)
        # def dfs(i, pre, m, n):
        #     if i == len(s):
        #         return n                
        #     if s[i] == pre:
        #         if m == 2:
        #             return dfs(i + 1, s[i], m, n)
        #         else:
        #             return dfs(i + 1, s[i], m + 1, n + s[i])
        #     else:
        #         return dfs(i + 1, s[i], 1, n + s[i])    
        # return dfs(0, "", 1, "")