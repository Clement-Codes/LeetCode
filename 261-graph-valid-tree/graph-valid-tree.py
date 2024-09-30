class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if n == 0: return True

        mapper = {i:[] for i in range(n)}
        for i in edges:
            mapper[i[0]].append(i[1])
            mapper[i[1]].append(i[0])
        
        visited = set()
        prev = -1
        def dfs(i, prev):
            if i in visited: return False
            visited.add(i)
            for j in mapper[i]:
                if j == prev:
                    continue
                elif not dfs(j, i):
                    return False
            
            return True
        return dfs(0, -1) and len(visited) == n