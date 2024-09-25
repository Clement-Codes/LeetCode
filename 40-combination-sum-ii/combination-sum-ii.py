class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        combination = []
        candidates.sort()
        def backtracking(index, total):
            if total == target:
                result.append(combination.copy())
                return
            if total > target or index >= len(candidates): return

            combination.append(candidates[index])
            backtracking(index + 1, total + candidates[index])

            combination.pop()
            while index + 1 < len(candidates) and candidates[index] == candidates[index + 1]: index += 1
            backtracking(index + 1, total)
        backtracking(0,0)
        return result