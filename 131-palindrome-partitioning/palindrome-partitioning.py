class Solution:
    def partition(self, s: str) -> List[List[str]]:
        path = []
        result = []

        def palidome(s, l, r):
            while l < r:
                if s[l] != s[r]:
                    return False
                l, r = l + 1, r - 1
            return True

        def backtracking(index):
            if index >= len(s): 
                result.append(path.copy())
                return
            for i in range(index, len(s)):
                if palidome(s, index, i):
                    path.append(s[index: i + 1])
                    backtracking(i + 1)
                    path.pop()

        backtracking(0)
        return result
