class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        moves = {
            0: [1, 3],
            1: [0, 2, 4],
            2: [1, 5],
            3: [0, 4],
            4: [1, 3, 5],
            5: [2, 4]
        }

        b = ''.join([str(c) for r in board for c in r])

        final = "123450"

        queue = deque([(b.index('0'), 0, b)])
        visited = set([b])

        while queue:
            location, length, t = queue.popleft()
            if t == final:
                return length
            tt = list(t)
            for i in moves[location]:
                ttt = tt.copy()
                ttt[location], ttt[i] = ttt[i], ttt[location]
                tttt = "".join(ttt)
                if  tttt not in visited:
                    visited.add(tttt)
                    queue.append((i, length + 1, tttt))
        return -1