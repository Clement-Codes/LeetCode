class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        mapper = defaultdict(list)
        for u, v, w in times:
            mapper[u].append([v, w])
        
        visited = set()
        h = [[0,k]]
        t = 0
        while h:
            w, v = heapq.heappop(h)
            if v in visited:
                continue
            t = max(t, w)
            visited.add(v)
            for vv, ww in mapper[v]:
                if vv not in visited:
                    heapq.heappush(h, [ww + t, vv])
        
        return t if len(visited) == n else -1