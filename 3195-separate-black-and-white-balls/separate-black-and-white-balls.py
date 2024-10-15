class Solution:
    def minimumSteps(self, s: str) -> int:
        # swaps = 0
        # white = 0
        # for i in range(len(s)):
        #     if s[i] == '0':
        #         swaps += i - white
        #         white += 1
        # return swaps                
        swaps = 0
        black = 0
        for i in s:
            if i == '1':
                black += 1
            else:
                swaps += black
        return swaps

