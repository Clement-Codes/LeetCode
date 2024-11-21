class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        arr = [[0 for _ in range(n)] for _ in range(m)]
        for r, c in walls:
            arr[r][c] = 1

        for r, c in guards:
            arr[r][c] = -1

        for r, c in guards:
            rr = r
            while 0 < rr:
                rr -= 1
                if arr[rr][c] == 1 or arr[rr][c] == -1:
                    break
                arr[rr][c] = -2
            rr = r
            while rr < m -1 :
                rr += 1
                if arr[rr][c] == 1 or arr[rr][c] == -1:
                    break
                arr[rr][c] = -2
            cc = c
            while 0 < cc:
                cc -= 1
                if arr[r][cc] == 1 or arr[r][cc] == -1:
                    break
                arr[r][cc] = -2
            cc = c
            while cc < n -1 :
                cc += 1
                if arr[r][cc] == 1 or arr[r][cc] == -1: 
                    break
                arr[r][cc] = -2
        
        result = 0
        for i in arr:
            print(i)
            for j in i:
                if j == 0:
                    result += 1
        return result