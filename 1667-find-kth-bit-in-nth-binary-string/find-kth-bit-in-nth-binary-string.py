class Solution:
    
    def findKthBit(self, n: int, k: int) -> str:
        def inverse(strs):
            result = ""
            for s in strs:
                if s == '0':
                    result += '1'
                else:
                    result += '0'
            return result

        def dfs(i):
            if i == 1:
                return '0'

            return dfs(i-1) + "1" + inverse(dfs(i-1))[::-1]

        return dfs(n)[k - 1]