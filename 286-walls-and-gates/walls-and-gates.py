class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        row = len(rooms)
        col = len(rooms[0])

        gates = deque()
        visited = set()

        for r in range(row):
            for c in range(col):
                if rooms[r][c] == 0:
                    gates.append((r, c))
                    visited.add((r,c))

        distance = 0
        while gates:
            for _ in range(len(gates)):
                i, j = gates.popleft()
                rooms[i][j] = distance
                for neighbour in [[1,0], [0,1], [-1, 0], [0, -1]]:
                    ni = i + neighbour[0]
                    nj = j + neighbour[1]
                    if ni >= 0 and nj >= 0 and ni < row and nj < col and rooms[ni][nj] != -1 and (ni,nj) not in visited:
                        gates.append((ni, nj))
                        visited.add((ni,nj))
            distance += 1