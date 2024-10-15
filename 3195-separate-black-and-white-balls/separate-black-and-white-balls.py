class Solution:
    def minimumSteps(self, s: str) -> int:
        swaps = 0
        black = 0
        for i in s:
            if i == '1':
                black += 1
            else:
                swaps += black
        return swaps