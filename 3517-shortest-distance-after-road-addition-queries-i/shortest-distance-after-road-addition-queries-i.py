class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        adj = [[i + 1] for i in range(n - 1)]

        def shortestPath(query):
            adj[query[0]].append(query[1])
            #bfs
            queue = deque([(0, 0)])
            visited = set([0])
            while queue:
                pos, l = queue.popleft()
                if pos == n-1:
                    return l
                for i in adj[pos]:
                    if i not in visited:
                        visited.add(i)
                        queue.append((i, l+1))
            
        result = []
        for query in queries:
            result.append(shortestPath(query))
        return result

            