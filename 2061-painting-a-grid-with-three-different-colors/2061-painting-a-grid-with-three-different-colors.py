class Solution:
    MOD = 10**9 + 7
    def __init__(self):
        self.state_mem = [[-1] * 1024 for _ in range(1002)]

    def colorTheGrid(self, m: int, n: int) -> int:
        return self.countWay(m, n, 0, 0, 0, 0)
    
    def countWay(self, m, n, r, c, curr, prev):
        if c == n:
            return 1
        if r == m:
            return self.countWay(m, n, 0, c + 1, 0, curr)
        if r == 0 and self.state_mem[c][prev] != -1:
            return self.state_mem[c][prev]
        
        up_color = 0
        if r > 0:
            up_color = curr & 3
        
        left_color = (prev >> ((m - r - 1) * 2)) & 3

        ways_to_color = 0
        for color in range(1, 4):
            if color != up_color and color != left_color:
                new_state = (curr << 2) | color
                ways_to_color = (ways_to_color + self.countWay(m, n, r + 1, c, new_state, prev)) %self.MOD

        if r == 0:
            self.state_mem[c][prev] = ways_to_color
        return ways_to_color