class Solution:
    
    def findKthBit(self, n: int, k: int) -> str:
        cache = {}
        def inverse(strs):
            result = ""
            for s in strs:
                if s == '0':
                    result += '1'
                else:
                    result += '0'
            return result

        def dfs(i):
            if i in cache: return cache[i]
            if i == 1:
                return '0'

            cache[i] = dfs(i-1) + "1" + inverse(dfs(i-1))[::-1]
            return cache[i]

        return dfs(n)[k - 1]